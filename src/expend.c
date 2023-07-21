/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:50:31 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/21 14:57:17 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *change_variable_to_content(char *var, char **env)
{
	char *str;
	short	i;

	i = 0;
	str = NULL;
	++var;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, (int)ft_strlen(var) == 0))
		{
			str = malloc(sizeof(char) * (ft_strlen(var) + 1));
				if (!str)
			ft_putstr_fd(var, 1);
			printf("-------\n");
					return (NULL);
			ft_strlcpy(str, var, ft_strlen(var));
			break;
		}
		++i;
	}
	ft_putstr_fd(str, 1);
	if (!str)
		return (NULL);
	return (str);
}

char **main_expend(char **str, char **env)
{
	short	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '$')
		{
			str[i] = change_variable_to_content(str[i], env);
		}
		++i;
	}
	return (str);
}

// int main (int ac, char **av, char **env)
// {
// 	if (ac < 1)
// 		return (1);
// 	main_expend(av, env);
// 	int i = 0;

// 	while (av[i])
// 	{
// 		printf("%s\n", av[i]);
// 		++i;
// 	}

// 	return (0);
// }
