/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:06:44 by hrobin            #+#    #+#             */
/*   Updated: 2023/07/24 20:06:44 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_type(t_types *current)
{
	if (*(char *)current->valeur == ' ' || *(char *)current->valeur == '\n'
            || *(char *)current->valeur == '\t')
            current->type = WSPACE;
    if ((*(char *)current->valeur >= '0' && *(char *)current->valeur <= '9')
            || (*(char *)current->valeur >= 'A'
				&& *(char *)current->valeur <= 'Z')
			|| (*(char *)current->valeur >= 'a'
				&& *(char *)current->valeur <= 'z'))
			current->type = ALNUM;
	if (*(char *)current->valeur == ';' || *(char *)current->valeur == '|'
            || *(char *)current->valeur == '&' || *(char *)current->valeur == '('
            || *(char *)current->valeur == ')' || *(char *)current->valeur == '<'
            || *(char *)current->valeur == '>')
			current->type = METACHAR;
	if (*(char *)current->valeur == '*' || *(char *)current->valeur == '@'
            || *(char *)current->valeur == '#' || *(char *)current->valeur == '?'
            || *(char *)current->valeur == '!' || *(char *)current->valeur == '-'
            || *(char *)current->valeur == '_' )
			current->type = VAR_SPE_ENV;
	if (*(char *)current->valeur == 34 || *(char *)current->valeur == 39)
			current->type = QUOTES;
	if (*(char *)current->valeur == '$')
			current->type = DOLLAR;
}

void	check_wspaces(t_types *head)
{
	t_types *current = head;
	bool	i;

	i = false;
	while (current)
	{
		if (current->type == QUOTES)
			i = true;
		if (i == false && current->type == WSPACE)
			current->type = NO_PRINTABLE;
		printf("[%c,%d] ", *(char *)current->valeur,current->type);
		current = (t_types *)current->next;
	}
}
