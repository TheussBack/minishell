
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
