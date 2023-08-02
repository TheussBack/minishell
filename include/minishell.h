/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:25:16 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/31 14:20:31 by louislaparr      ###   ########.fr       */
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
	struct t_types	*next;
	struct s_types	*prev;
}					t_types;

// create list //

//void 	free_doubly_linked_list(t_types *head);
void    parsing_main(char *input);

// expand //
char 	**main_expend(char **str, char **env);

// builtins //
void	builtin_echo(char **str);
void	builtin_pwd(char **env);
void	builtin_cd(int ac, char **av);

// type //
void	create_type(t_types *current);

#endif
