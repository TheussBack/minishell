/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:25:16 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/26 21:52:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include "error.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define	ALNUM 0
# define	WSPACE 1
# define	PARAPSP 2
# define	MCHAR 3

// prout //

// struct //

typedef struct s_types
{
	void			*valeur;
	int				type;
	struct t_types	*next;
	struct s_types	*prev;
}					t_types;

// create list //

void	add_type(char *input);
void free_doubly_linked_list(t_types *head);
t_types *string_to_doubly_linked_list(const char *input);
t_types *create_node(void *valeur, int type);

// expand //
char **main_expend(char **str, char **env);

// builtins //
void	builtin_echo(char **str);
void	builtin_pwd(char **env);
void	builtin_cd(int ac, char **av);

// type //
void	create_type(t_types *current);

#endif
