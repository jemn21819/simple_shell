#include "holberton.h"

/**
* run_cmd - creates a child process to execute
* @path: pointer to tokenized path
* @av: pointer to the argument array
* @env: pointer to the enivornment of the user
* Return: Status sucess, -1 on failure
*/

int run_cmd(const char *path, char **av, char **env)
{
	pid_t pid;
	int status = 0;

	pid = fork();


	if (pid == -1)
	{
		perror("Error:");
		free(av);
		free(env);
		 exit(1);
	}

	if (pid == 0)
	{
		if (execve(path, av, env) == -1)
		{
			perror("Error:");
			free(av);
			free(env);
			exit(0);
		}
	}
	else
	{
		wait(&status);
		status = WEXITSTATUS(status);
		return (status);
	}

	return (-1);
}

/**
* exe_cmd - run command if it is a builtin absolute
* @av: pointer to the argument vector
* @env: pointer to user environment
* Return: success or 127 file not found
*/

int exe_cmd(char **av, char **env)
{
	char *path = av[0];
	int status = atoi(av[1]);

	if (_strcmp(path, "exit") == 0)
	{
		free(av);
		if (status)
		{
			exit(status);
		}
		else
		{
			exit(1);
		}
	}

	if (path[0] == '/' || path[0] == '.')
	{
		if (access(path, X_OK) == 0)
		{
			return (run_cmd(path, av, env));
		}
		_printstr("Fail in creation of new process.\n");
		return (127);
	}

	path = find_cmd(av[0], env);
	if (!path)
	{
		_printstr("Fail in the execution if process.\n");
		return (127);
	}
	return (run_cmd(path, av, env));
}
