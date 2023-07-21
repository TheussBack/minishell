/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:50:31 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/21 16:17:25 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*change_variable_to_content(char *var, char **env)
{
	char	*str;
	short	i;

	i = -1;
	str = NULL;
	++var;
	// je dois faire de ce code une fonction //
	while (var[++i])
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (var[i])
	{
		str[i] = var[i];
		++i;
		// printf("str[i] = %c\n", str[i]);
	}
	str[i++] = '=';
	str[i++] = '\0';
	// ------------------------------------ //
	// ft_strlcpy(str, var, i);
	ft_putstr_fd(str, 1);
	i = 0;
	while (env[i])
	{
		// je dois check si la variable existe pour ensuite changer ca valeur //
		if (ft_strncmp(env[i], str, (int)ft_strlen(str) == 0))
		{
			ft_putstr_fd(env[i], 1);
			str = malloc(sizeof(char) * (ft_strlen(var) + 1));
			if (!str)
				return (NULL);
			ft_putstr_fd(var, 1);
			printf("-------\n");
			ft_strlcpy(str, var, ft_strlen(var));
			break ;
		}
		++i;
	}
	ft_putstr_fd(str, 1);
	if (!str)
		return (NULL);
	return (str);
}

char	**main_expend(char **str, char **env)
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
