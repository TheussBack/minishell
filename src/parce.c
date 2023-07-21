/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:21:53 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/16 17:48:17 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strtok_custom(char *str, const char *delim)
{
	static char *token = NULL;
		// Variable statique pour stocker la position actuelle
	char *start = NULL;        // Pointeur vers le début de la sous-chaîne
	int found = 0;             // Indicateur de délimiteur trouvé
	if (str != NULL)
	{
		token = str; // Premier appel : initialisation de la position
	}
	// Recherche du prochain délimiteur ou de la fin de la chaîne
	while (*token != '\0')
	{
		if (strchr(delim, *token) != NULL)
		{
			if (found == 1)
			{
				*token = '\0';
				break ;
			}
		}
		else
		{
			if (found == 0)
			{
				start = token;
				found = 1;
			}
		}
		token++;
	}
	return (start);
}

void	parse_arguments(char *input)
{
	char	*token;

	// Utiliser strtok() pour découper l'entrée en arguments
	printf("input : %s\n", input);
	token = strtok_custom(input, " ");
	while (token != NULL)
	{
		printf("Argument : %s\n", token);
		token = strtok_custom(NULL, " ");
	}
}
