
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

static void	nb_of_char(t_types *current, int *end)
{
	while (current->type == current->next->type)
	{
		current = current->next;
		*end += 1;
	}
}

static void	make_line(t_types *current, char **tab, int i, int nb)
{
	int	start;
	int	end;
	int	j;

	start = 0;
	end = 1;
	while (current)
	{
		printf("start%i\nend%i\n", start, end);
		nb_of_char(current, &end);
		printf("---start%i\n---end%i\n", start, end);
		if (end > start)
			tab[i] = malloc(sizeof(char) * (end - start) + 1);
			if (!tab[i])
				return;
		j = 0;
		while (start < end)
		{
			tab[i][j] = *((char*)current->valeur);
			++start;
			++j;
			printf("START=%i\n", j);
			current = current->next;
		}
		tab[i][j] = '\0';
		//int	a = 0;
		//while (tab[a])
		//{
		//	printf("tab[i] = %s\n", tab[a]);
		//	++a;
		//}
		start = end;
		++end;
		++i;
		printf("___i=%i\n___nb=%i", i, nb);
		if (i == (nb -1))
			return ;
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
	make_line(current, &tab[i], i, nb);
	tab[i] = NULL;

	int	a = 0;
	while (tab[a])
	{
		printf("tab[i] = %s\n", tab[a]);
		++a;
	}
	return (0);
}
