#include "holberton.h"


/**
 * prompt - Prints a shell prompt to stdout.
 */

void prompt(void)
{
	_printf("$ ");
}


/**
 * main - main function.
 * @ac: Argument count.
 * @av: Argument vector.
 * @env: Environment variables.
 * Return: status
 */

int main(int ac, char **av, char **env)
{
	char *line;
	char **tokens;
	int status;
	(void)ac;
	(void)av;

	status = 1;
	tokens = NULL;
	line = NULL;

	signal(SIGINT, handler);
	while (status == 1)
	{
		prompt();
		line = _getline();
		tokens = _strtok(line);
		status = exec_bltin(tokens, env, status, line);
	}
	free(tokens);
	return (status);
}
