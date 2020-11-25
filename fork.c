#include "holberton.h"
/**
 * _fork - creates child process.
 * @args: array of strings.
 * @argv: argument vector.
 * @env: environment variables.
 * @line: user's input.
 * @count: number of times the loop has executed.
 * Return: nothing
 */
void _fork(char **args, char **argv, char **env, char *line, int count)
{
	int status;
	pid_t pid;
	struct stat fStat;
	char *exit_cmd = "exit", *env_cmd = "env";

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
}
