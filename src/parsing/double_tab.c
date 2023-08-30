
#include "minishell.h"

static int	count_nb_of_tab(t_types *current)
{
	int	nb;

	nb = 1;
	while (current)
	{
		if (current->type == NO_PRINTABLE)
			current = (t_types *)current->next;
		if (current->prev != NULL)
			if ((current->type != current->prev->type) && (current->type != NO_PRINTABLE))
				nb++;
		current = (t_types *)current->next;
	}
	return (nb);
}

static void	make_line(t_types *current, char **tab, int i)
{
	int	start;
	int	end;
	int	j;

	start = 0;
	end = 0;
	while (current)
	{
		if (current->type == current->next->type)
			++end;
		if (end > start)
			tab[i] = malloc(sizeof(char) * (end - start) + 1); // malloc a proteger
		j = 0;
		while (start < end)
		{
			tab[i][j] = *((char*)current->valeur);
			++start;										// seg fault a gerer
			++j;
			current = (t_types *)current->next;
		}
		tab[i][j] = '\0';
		start = end;
		++i;
		write(1, "\n-----\n", 7);
	}
}

int	create_double_tab(t_types *head)
{
	int nb;
	int i;
	t_types *current;
	char **tab;

	current = head;
	nb = count_nb_of_tab(current);
	tab = malloc(sizeof (char *) * nb);
	if (!tab)
		return (1);
	current = head;
	i = 0;
	make_line(current, &tab[i], i);
	tab[i] = NULL;

	int	a = 0;
	while (tab[a])
	{
		printf("tab[i] = %s\n", tab[a]);
		++a;
	}
	return (0);
}
