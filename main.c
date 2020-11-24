#include "holberton.h"

#include "holberton.h"
/**
 * INThandler - handles signals and write the prompt
 * @sig: signal to handle
 * Return: void
 */
void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - basic shell recreation
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on exit, 1 if any failures happen
 */
int main(int argc, char **argv, char **env)
{
	char *line; char **args;
	size_t size; ssize_t chr;
	char *prompt = "$ ", *exit_cmd = "exit", *env_cmd= "env";
	pid_t pid; struct stat fStat;
	int status, count;
	(void)argc;

	line = NULL, size = 0, count = 0;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 2);
	signal(SIGINT, handler);
	while ((chr = getline(&line, &size, stdin)))
	{
		if (chr == EOF)
			end_of_file(line);
		++count;
		args = array_from_strtok(line);
		pid = fork();
		if (pid == -1)
			fork_fail();
		if (pid == 0)
		{
			if (args == NULL)
				cmd_null(line);
			else if (_strcmp(exit_cmd, args[0]))
				exit_out(line, args);
			else if (_strcmp(env_cmd, args[0]))
				env_out(line, args, env);
			else if (stat(args[0], &fStat) == 0)
				execve(args[0], args, NULL);
			else
				c_path(args, line, env, argv, count);
		}
		else
		{
			wait(&status);
			if (args == NULL)
				parent_free(line, args);
			else if (_strcmp(exit_cmd, args[0]))
				exit_out(line, args);
			else
				parent_free(line, args);
		}
		size = 0; line = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
	}
	if (chr == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
