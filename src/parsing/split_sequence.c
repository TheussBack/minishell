
#include "minishell.h"

static int is_valid_type(int type)
{
	return (type != NO_PRINTABLE && type != WSPACE);
}

	// Comptez la longueur de la séquence et vérifiez les types sont valides.
static	size_t	sequence_len(t_types *head)
{
	t_types *current;
	current = head;
	size_t	length;

	length = 0;
	while (current)
	{
		if (is_valid_type(current->type))
		{
			++length;
			current = current->next;
		}
		else
		{
			current = current->next;
			while (current && !is_valid_type(current->type))
				current = current->next;
		}
	}
	return (length);
}

char **split_sequence(t_types *head)
{
	t_types *current = head;
	size_t sequence_length = 0;
	char **result = NULL;


	sequence_length = sequence_len(head);
	// Allouez de la mémoire pour le tableau résultant.
	result = (char **)malloc(sizeof(char *) * (sequence_length + 1));
	if (!result)
	{
		perror("Allocation de mémoire échouée");
		return (NULL);
	}

	// Remplissez le tableau résultant avec les séquences valides.
	current = head;
	size_t i = 0;
	while (current)
	{
		if (is_valid_type(current->type))
		{
			size_t sequence_length = 0;
			t_types *sequence_start = current;

			// Trouvez la fin de la séquence.
			while (current && is_valid_type(current->type)) // cette boucle dans une fonction
			{
				++sequence_length;
				current = current->next;
			}

			// Allouez de la mémoire pour stocker la séquence.
			result[i] = (char *)malloc(sizeof(char) * (sequence_length + 1));
			if (!result[i])
			{
				perror("Allocation de mémoire échouée");
				return (NULL);
			}

			// Copiez la séquence dans le tableau.
			current = sequence_start;
			size_t j = 0;

			while (current && is_valid_type(current->type)) // cette boucle dans une fonction
			{
				result[i][j] = *((char *)current->valeur);
				current = current->next;
				++j;
			}
			result[i][j] = '\0';
			++i;
		}
		else
		{
			current = current->next;
		}
	}

	result[sequence_length] = NULL; // Marquez la fin du tableau.
	return result;
}


//static int	count_nb_of_tab(t_types *current)
//{
//	int	nb;

//	nb = 1;
//	while (current)
//	{
//		if (current->type == NO_PRINTABLE)
//			current = (t_types *)current->next;
//		if (current->prev != NULL)
//			if ((current->type != current->prev->type) && (current->type != NO_PRINTABLE))
//				nb++;
//		current = (t_types *)current->next;
//	}
//	return (nb);
//}

//static void	nb_of_char(t_types *current, int *end)
//{
//	while (current->type == current->next->type)
//	{
//		current = current->next;
//		*end += 1;
//	}
//}

//static void	make_line(t_types *current, char **tab, int i, int nb)
//{
//	int	start;
//	int	end;
//	int	j;

//	start = 0;
//	end = 1;
//	while (current && i < nb)
//	{
//		printf("start%i\nend%i\n", start, end);
//		nb_of_char(current, &end);
//		printf("---start%i\n---end%i\n", start, end);
//		if (end > start)
//			tab[i] = malloc(sizeof(char) * (end - start) + 1);
//			if (!tab[i])
//				return;
//		j = 0;
//		while (start < end)
//		{
//			tab[i][j] = *((char*)current->valeur);
//			++start;
//			++j;
//			printf("START=%i\n", j);
//			current = current->next;
//		}
//		tab[i][j] = '\0';
//		start = end;
//		++end;
//		++i;
//		printf("___i=%i\n___nb=%i", i, nb);
//		if (i == (nb -1))
//			return ;
//	}
//}

//int	create_double_tab(t_types *head)
//{
//	int nb;
//	int i;
//	t_types *current;
//	char **tab;

//	current = head;
//	nb = count_nb_of_tab(current);
//	tab = malloc(sizeof (char *) * nb);
//	if (!tab)
//		return (1);
//	current = head;
//	i = 0;
//	make_line(current, &tab[i], i, nb);
//	tab[i] = NULL;

//	int	a = 0;
//	while (tab[a])
//	{
//		printf("tab[i] = %s\n", tab[a]);
//		++a;
//	}
//	return (0);
//}

