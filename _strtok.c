#include "holberton.h"

/**
 * _strtok - Tokenize string.
 * @line: String to be tokenized.
 * Return: double pointer array.
 */

char **_strtok(char *line)
{
	char **tokens;
	char *args;
	int i, len;

	len = 0;
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ' || line[i] == '\n')
		{
			len++;
		}
	}
	len++;

	tokens = malloc(sizeof(char *) * len);
	if (!tokens)
	{
		_printf("Error: malloc - parse_line\n");
		return (NULL);
	}

	args = strtok(line, "\n ");
	for (i = 0; args; i++)
	{
		tokens[i] = args;
		args = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
