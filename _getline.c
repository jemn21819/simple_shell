#include "holberton.h"

/**
 * _getline - get command from stdin.
 * Return: pointer command line input.
 */

char *_getline()
{
	char *line;
	size_t bufsize;
	int line_len;

	line = NULL;
	bufsize = 0;
	line_len = getline(&line, &bufsize, stdin);

	if (line_len == -1)
	{
		_printf("nothing entered\n");
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
