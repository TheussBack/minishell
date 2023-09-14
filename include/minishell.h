/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:25:16 by hrobin            #+#    #+#             */
/*   Updated: 2023/08/30 16:51:48 by marvin           ###   ########.fr       */
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
# define	VAR_SPE_ENV 2
# define	METACHAR 3
# define	QUOTES 4
# define	DOLLAR 5
# define	NO_PRINTABLE 6

// struct //

typedef struct s_types
{
	void			*valeur;
	int				type;
	struct s_types	*next;
	struct s_types	*prev;
}					t_types;

// create list //

//void 	free_doubly_linked_list(t_types *head);
void    parsing_main(char *input, char **env);

// expand //
char 	**main_expend(char **str, char **env);

// builtins //
void	builtin_echo(char **str);
void	builtin_pwd(char **env);
void	builtin_cd(int ac, char **av);

// type //
void	create_type(t_types *current);
void	check_wspaces(t_types *head);

char **split_sequence(t_types *head);

//utils//
int	h_strcmp(char *s1, char *s2);

#endif
