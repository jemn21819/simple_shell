#include "holberton.h"

/**
 * exec_bltin - Executes builtins and calls programs.
 * @tokens: received from stdin.
 * @env: environment variable array.
 * @status: return value
 * @line: command input.
 * Return: status (int).
 */

int exec_bltin(char **tokens, char **env, int status, char *line)
{
	char *int_to_str;

	if (tokens[0] == NULL)
	{
		free(tokens);
		free(line);
		return (1);
	}
	else if (_strcmp(tokens[0], "exit") == 0)
		exit_shell(tokens, line);
	else if (_strcmp(tokens[0], "env") == 0)
	{
		free(tokens);
		free(line);
		return (_env(env));
	}
	else if (_strcmp(tokens[0], "$?") == 0)
	{
		free(tokens);
		free(line);
		int_to_str = _itoa(status);
		_printf(int_to_str);
		_printf("\n");
		free(int_to_str);
	}
	else if (_strcmp(tokens[0], "$$") == 0)
	{
		free(tokens);
		free(line);
		int_to_str = _itoa(getpid());
		_printf(int_to_str);
		_printf("\n");
		free(int_to_str);
	}
	else
		exec_prgrms(tokens, line);
	return (1);
}


/**
 * exec_prgrms - Executes shell programs with fork process.
 * @tokens: Commands from stdin.
 * @line: Commands from stdin.
 * Return: status (int).
 */

int exec_prgrms(char **tokens, char *line)
{
	char *env_var;
	char *env_var_val;
	char *full_comd_path;
	pid_t pid;
	int status;

	env_var = "PATH";
	env_var_val = get_env_var_val(env_var);
	full_comd_path = get_full_comd_path(tokens, env_var_val);

	if (full_comd_path != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(full_comd_path);
			return (1);
		}
		if (pid == 0)
		{
			if (execve(full_comd_path, tokens, environ) == -1)
			{
				perror(*tokens);
				free(tokens);
				free(env_var_val);
				free(full_comd_path);
				exit(EXIT_FAILURE);
			}
			return (EXIT_SUCCESS);
		}
		wait(&status);
	}
	free(line);
	free(tokens);
	free(env_var_val);
	free(full_comd_path);
	return (0);
}
