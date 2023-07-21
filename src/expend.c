/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:50:31 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/21 14:06:04 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *change_str(char *str, char *var, char **env, short i)
{
	str

}

char *change_variable_to_content(char *var, char **env)
{
	char *str;
	short	i;

			str = change_str(str, var, env, i);

	i = 0;
	str = NULL;
	++var;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var) == 0))
		{
			str = malloc(sizeof(char) * (ft_strlen(var) + 1));
				if (!str)
					return (NULL);
			ft_strlcpy()
			break;
		}
		++i;
	}
	return (str);
}

char **main_expend(char **str, char **env)
{
	short	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '$')
			str[i] = change_variable_to_content(str[i], env);
		++i;
	}
}
