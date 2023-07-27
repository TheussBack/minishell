/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:08:03 by lolaparr          #+#    #+#             */
/*   Updated: 2023/07/27 19:59:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_INPUT_LENGTH 100

int	main(int ac, char **av)
{
	char	*input;
	// char **str;

	input = NULL;
	while (1)
	{
		input = readline("$ ");
		if (input == NULL)
			break ;
		add_history(input);
		input[strcspn(input, "\n")] = '\0';
		add_type(input);
		// str = ft_split(input, ' ');
		// main_expend(str, env);

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
