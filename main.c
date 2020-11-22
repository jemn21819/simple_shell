#include "holberton.h"

/**
 * main - command line interpreter and start point of program
 * @ac: arg counter
 * @av: arg vector
 * @env: pointer to user enviroment
 * Return: status
 */

int main(int  ac, char **av, char **env)
{
	char *line;
	char **args;
	size_t size;
	int status;

	signal(SIGINT, handler);
	while (1)
	{
		line = NULL;
		size = 0;

		if (isatty(STDIN_FILENO) == 1)
			_printstr("$ ");

		if (getline(&line, &size, stdin) == EOF)
		{
			if (isatty(0) == 1)
				_printstr("\n");
			break;
		}

		args = tokenizer(line, " \n\t");
		if (args != NULL)
		{
			status = exe_cmd(args, env);
		}
		free(line);
		free(args);
	}
	(void)ac;
	(void)av;
	return (status);
}
