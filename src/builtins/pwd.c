/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:49:57 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/15 14:49:59 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(char **env)
{
	short unsigned int	i;
	short unsigned int	j;

	i = -1;
	j = 0;
	//je recup la ligne qu'il faut print
	while (env[++i])
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
			j = i;
	// je passe les 5 premiers char
	env[j] += 5;
	// je print
	ft_putstr_fd(env[j], 1);
	write(1, "\n", 1);
}
