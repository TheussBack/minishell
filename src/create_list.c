/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:24:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/20 15:26:51 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to create a new node for the doubly linked list
t_types *create_node(void *valeur, int type)
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
t_types *string_to_doubly_linked_list(const char *input)
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


// pour free
void free_doubly_linked_list(t_types *head)
{
    t_types *current = head;
    while (current)
    {
        t_types *next = (t_types *)current->next;
        free(current->valeur);
        free(current);
        current = next;
    }
}

void	add_type(char *input)
{
    t_types *head = string_to_doubly_linked_list(input);

    // on parcours la list
    t_types *current = head;
    while (current)
    {
        if (*(char *)current->valeur == ' ' || *(char *)current->valeur == '\n'
            || *(char *)current->valeur == '\t')
            current->type = WSPACE;
        if ()
        printf("[%c,%d] ", *(char *)current->valeur,current->type);
        current = (t_types *)current->next;
    }
    // Free
    free_doubly_linked_list(head);

    return ;
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

