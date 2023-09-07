/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:08:03 by lolaparr          #+#    #+#             */
/*   Updated: 2023/09/07 17:20:50 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_INPUT_LENGTH 100

int	main(int ac, char **av, char **env)
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
		parsing_main(input, env);
		// str = ft_split(input, ' ');
		// main_expend(str, env);

		free(input);
	}
	clear_history();
	printf("\n\nJ'ai lu : %s, %i\n", av[1], ac);
	return (0);
}
