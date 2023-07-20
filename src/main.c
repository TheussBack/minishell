/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:42:42 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/20 14:20:23 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_INPUT_LENGTH 100

int	main(int ac, char **av)
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
		add_type(input);
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
