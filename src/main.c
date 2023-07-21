/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:42:42 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/16 17:08:08 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_INPUT_LENGTH 100

int	main(int ac, char **av, char **env)
{
	char	*input;

	input = NULL;
	while (1)
	{
		input = readline("$ ");
		if (input == NULL)
			break ;
		add_history(input);
		input[strcspn(input, "\n")] = '\0';
		if (ft_strncmp(input, "cd", 2) == 0)
		{
			char **sttr = ft_split(input, ' ');
			int i = -1;
			while (sttr[++i])
			builtin_cd(i, sttr);
		}
		if (ft_strncmp(input, "pwd", 3) == 0)
			builtin_pwd(env);
		if (ft_strncmp(input, "echo", 4) == 0)
		{
			char **str = ft_split(input, ' ');
			builtin_echo(str);
		}
		parse_arguments(input);
		free(input);
	}
	rl_clear_history();
	printf("\n\nJ'ai lu : %s, %i\n", av[1], ac);
	return (0);
}

//Gerer un prompt
//visuellement
//y rentrer des commandes
//parser les arguments rentres
//comme pipex ?
//les exec
//afficher
