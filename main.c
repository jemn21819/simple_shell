#include "holberton.h"
/**
 * main - basic shell recreation
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on exit, 1 if any failures happen
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL, **args, *prompt = "$ ";
	size_t size = 0;
	ssize_t chr;
	int count = 0;
	(void)argc;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 2);

	signal(SIGINT, handler);
	while ((chr = getline(&line, &size, stdin)))
	{
		if (chr == EOF)
			end_of_file(line);

		++count;
		args = arr_strtok(line);
		_fork(args, argv, env, line, count);
		size = 0;
		line = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
	}
	if (chr == -1)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
