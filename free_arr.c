#include "holberton.h"

/**
 * free_str_array - Frees a string array.
 * @array: array to set free.
 */

void free_str_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
