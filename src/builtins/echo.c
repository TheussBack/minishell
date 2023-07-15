/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:22:50 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/15 14:56:42 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **str)
{
	short unsigned int	i;
	bool				arg;

	i = 1;
	arg = false;
	//si il ny a pas d'argument a echo
	if (!str[1])
		return (ft_putchar_fd('\n', 1));
	//si il y a l'argument '-n' je passe le bool a true
	//ce qui veut dire qu'on ne doit pas mettre de '\n' a la fin
	if (str[i][0] == '-' && str[i][1] == 'n')
	{
		arg = true;
		++i;
	}
	//je print les arguments
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		++i;
	}
	if (arg == false)
		ft_putchar_fd('\n', 1);
}
