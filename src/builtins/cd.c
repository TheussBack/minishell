/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:27:00 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/15 15:09:57 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd(int ac, char **av)
{
	char	cwd[1024];

	if (ac != 2)
		return (ft_putstr_fd("cd: no such file or directory: %s\n", 1));
	if (chdir(av[1]) != 0)
		return (ft_putstr_fd("chdir fail\n", 1));
	if (getcwd(cwd, 1024) != 0)
		return (ft_putstr_fd("getcwd fail\n", 1));
}
