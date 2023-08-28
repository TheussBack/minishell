/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:24:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/08/22 18:24:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to create a new node for the doubly linked list
static t_types *create_node(void *valeur, int type)
{
    t_types *node = (t_types *)malloc(sizeof(t_types));
    if (node)
    {
        node->valeur = valeur;
        node->type = type;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

// string a liste chainnnnn
static t_types *string_to_doubly_linked_list(const char *input)
{
    t_types *head = NULL;
    t_types *tail = NULL;
    int i = 0;
    char currentChar;
    while ((currentChar = input[i]) != '\0')
    {
        char *character = (char *)malloc(sizeof(char));
        *character = currentChar;
        t_types *node = create_node(character, 0);
        if (node == NULL)
        {
            // gerrer l'erreur d'alloc
            return NULL;
        }
        if (head == NULL) // si c'est le debut de la liste chainee
        {
            head = node;
            tail = node;
        }
        else
        {

            tail->next = (struct t_types *)node;
            node->prev = tail;
            tail = node;
        }
        i++;
    }
    return head;
}


//void free_doubly_linked_list(t_types *head)
//{
//    t_types *current = head;
//    while (current)
//    {
//        t_types *next = (t_types *)current->next;
//        free(current->valeur);
//        free(current);
//        current = next;
//    }
//}

static void	add_type(t_types *current)
{
    // on parcours la list
    while (current)
    {
        create_type(current);
        current = (t_types *)current->next;
    }

    //free_doubly_linked_list(head);

    return ;
}

//tg pute//
static void    change_quotes_type(t_types *head)
{
    t_types *current = head;

    while (current)
    {
        if (current->type == QUOTES && *(char *)current->valeur == 34) // double = 34 //
        {
            current->type = NO_PRINTABLE;
            printf("[%c,%d] ", *(char *)current->valeur,current->type);
            current = (t_types *)current->next;
            while (*(char *)current->valeur != 34)
            {
                if (current->type != DOLLAR && current->type != VAR_SPE_ENV)
                    current->type = ALNUM;
                printf("[%c,%d] ", *(char *)current->valeur,current->type);
                current = (t_types *)current->next;
            }
            current->type = NO_PRINTABLE;
        }
        if (current->type == QUOTES && *(char *)current->valeur == 39) // single = 39 //
        {
            current->type = NO_PRINTABLE;
            printf("[%c,%d] ", *(char *)current->valeur,current->type);
            current = (t_types *)current->next;
            while (*(char *)current->valeur != 39)
            {
                current->type = ALNUM;
                printf("[%c,%d] ", *(char *)current->valeur,current->type);
                current = (t_types *)current->next;
            }
            current->type = NO_PRINTABLE;
        }
        printf("[%c,%d] ", *(char *)current->valeur,current->type);
        current = (t_types *)current->next;
    }

}

static void erase_And_Free_Node(t_types *node)
{
    // if (node == nullptr)
    // {
    //     return; // Nothing to erase if the node is nullptr
    // }

    t_types* prevNode = (t_types *)node->prev;
    t_types* nextNode = (t_types *)node->next;

    // Update previous node's next pointer
    if (prevNode != NULL) {
        (t_types *)prevNode->next = nextNode;
    }

    // Update next node's prev pointer
    if (nextNode != NULL) {
        (t_types *)nextNode->prev = prevNode;
    }
    // Update previous node's next pointer
    free(node);
}

static void delete_no_printable(t_types *head)
{
    t_types *tmp;
    t_types *current;

    current = head;
    while (current)
    {
        if (current->next->type == NO_PRINTABLE)
        {
            tmp = current;
            tmp = (t_types *)tmp->next;
            erase_And_Free_Node(tmp);
        }
        current = (t_types *)current->next;
    }

}

// il faut rajouter les types pour le '=' //

void    parsing_main(char *input)
{
    t_types *head = string_to_doubly_linked_list(input);
    t_types *current = head;

    add_type(current);
    change_quotes_type(head);
    delete_no_printable(head);
}


// void	print_input(char *input)
// {
//     t_types *head = string_to_doubly_linked_list(input);

//     // on parcours la list
//     t_types *current = head;
//     while (current)
//     {
//         printf("%c ", *((char *)(current->valeur)));
//         current = (t_types *)current->next;
//     }

//     // Free
//     free_doubly_linked_list(head);

//     return ;
// }
