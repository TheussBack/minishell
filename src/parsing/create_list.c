/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:24:15 by hrobin            #+#    #+#             */
/*   Updated: 2023/09/14 15:22:26 by hrobin           ###   ########.fr       */
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

            tail->next = node;
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

// static void erase_And_Free_Node(t_types *node)
// {
//     struct s_types* prevNode = NULL;
//     struct t_types* nextNode = NULL;

//     prevNode = node->prev;
//     nextNode = node->next;

//     // Update previous node's next pointer
//     if (prevNode != NULL) {
//         prevNode->next = nextNode;
//     }

//     // Update next node's prev pointer
//     if (nextNode != NULL) {
//         nextNode->prev = prevNode;
//     }
//     // Update previous node's next pointer
//     free(node);
// }

// static void delete_no_printable(t_types *head)
// {
//     t_types *tmp;
//     t_types *current;

//     current = head;
//     while (current)
//     {
//         if (current->next->type == NO_PRINTABLE)
//         {
//             tmp = current;
//             tmp = (t_types *)tmp->next;
//             erase_And_Free_Node(tmp);
//         }
//         current = (t_types *)current->next;
//     }

// }

static bool var_env(t_types *head)
{
    t_types *current = head;

    while (current)
    {
        if (current->type == DOLLAR)
            return (true);
        current = current->next;
    }
    return (false);
}

char *find_env_word(char ***tab, char ***env)
{
    size_t  i = 0;
    size_t  j = 0;
    size_t  k = 0;
    char    *exp;

    while (*tab[i])
    {
        while(*tab[i][j])
        {
            if (*tab[i][j] == '$' && *tab[i][j + 1] == '?')
                //faut remplacer par l'exit code

            else if (*tab[i][j] == '$' && (*tab[i][j+ 1] != ' ' && (*tab[i][j+ 1] != '"' // ici je trouve le mot apres le dollar je le recup et je le garde pour le chercher plus tard dans l'env//
					|| *tab[i][j+ 2] != '\0')) && *tab[i][j+ 1] != '\0')                   //exp c'est pour expend c'est une variale ou je met le mot//
            {
                j++;
                while(*tab[i][j] != WSPACE)
                {
                    exp[k] = *tab[i][j];
                    k++;
                    j++;
                }       
            }
                
            ++j;
        }
        ++i;
    }
    return (exp);
}

static void make_var_env(char ***tab, char ***env)
{
    char *word;

    word = find_env_word(tab, env); //on a donc le mot a chercher dans l'env//
    if (is_it_env(word))
    {
        //remplacer le mot i guess?//
    }
    else
        //erreur le $... n'existe pas//
    
}

// il faut rajouter les types pour le '=' //

void    parsing_main(char *input, char **env)
{
    t_types *head = string_to_doubly_linked_list(input);
    t_types *current = head;
    char    **tab;
    bool    env;

    env = false;
    add_type(current);
    change_quotes_type(head);
    printf("\n");
    check_wspaces(head);
    if (var_env(head) == true)
        env = true;
    tab = split_sequence(head);
    printf("\n");
    int	a = 0;
	while (tab[a])
	{
		printf("tab[i] = %s\n", tab[a]);
		++a;
	}
    if (env == true)
        make_var_env(&tab, env);

    // delete_no_printable(head);
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

