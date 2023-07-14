/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:42:42 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/14 16:51:18 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_INPUT_LENGTH 100

int main()
{
    char *input;

    while (1)
	{
        input = readline("$ ");

        if (input == NULL)
            break;
        add_history(input);
        input[strcspn(input, "\n")] = '\0';
        printf("J'ai lu : %s\n", input);
		parse_arguments(input);
        free(input);
    }
    rl_clear_history();

    return 0;
}

	//Gerer un prompt
		//visuellement
		//y rentrer des commandes
	//parser les arguments rentres
		//comme pipex ?
	//les exec
	//afficher
