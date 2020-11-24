#include "holberton.h"

/**
 * exit_shell - exits shell.
 * @tokens: Commands from stdin.
 * @line: Line from stdin.
 * Return: status (int).
 */

int exit_shell(char **tokens, char *line)
{
	int exit_value;

	exit_value = 0;

	if (tokens[1] != NULL)
	{
		exit_value = _atoi(tokens[1]);
	}
	free(tokens);
	free(line);
	exit(exit_value);
}
