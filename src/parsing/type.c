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
			current->type = MCHAR;
}
