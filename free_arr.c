#include "holberton.h"

/**
 * free_dptr - frees all the memory associated with a double pointer
 * @d_ptr: the double pointer to free
 */

void free_dptr(char **d_ptr)
{
	unsigned int i = 0;

	if (d_ptr == NULL)
		return;

	while (d_ptr[i])
	{
		free(d_ptr[i]);
		++i;
	}

	if (d_ptr[i] == NULL)
		free(d_ptr[i]);

	free(d_ptr);
}
/**
* handler - handles signals and write the prompt
* @sig: signal to handle
* Return: nothing
*/
void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * _atoi - converts from character to integer.
 * @str: string
 * Return: converted integer.
 */
int _atoi(char *str)
{
	int res = 0, sign = 1, i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}

	return (sign * res);
}
