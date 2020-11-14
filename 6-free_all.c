#include "holberton.h"

/**
 * free_pointers - frees pointers from memory.
 * @pointers: an array of pointers.
 * Return: nothing.
 */
void free_pointers(char **pointers)
{
	int i = 0;

	if (pointers == NULL)
	{
		return (NULL);
	}

	while (pointers[i])
	{
		free(pointers[i])
			i++;
	}

	if (pointers[i] == NULL)
	{
		free(pointer[i]);
	}

	free(pointers);
}
