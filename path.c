#include "holberton.h"

/**
* print_env - print enviroment
* Return: nothing
*/

void print_env(void)
{
	char **p_env;

	p_env = environ;
	while (*p_env)
	{
		write(, *p_env, _strlen(*p_env));
		write(1, "\n", 1);
		p_env++;
	}
}

/**
* _getenv - searches the environment for a string
* @key: keyword to look for
* Return: pointer to value of keyword variable
*/

char *_getenv(char *key)
{
	char *token;
	int i;

	i = 0;
	while (environ[i])
	{
		if (_strcmp(key, environ[i]) == 0)
		{
			token = _sublook(environ[i], key);
			if (token[0] == '=')
			{
				token = _char_locate(environ[i], '=');
				return (token);
			}
		}
		i++;
	}
	return (0);
}

/**
 * path - Find the path to a command.
 * @av: command to look for a path.
 * Return: A pointer created with malloc.
 */

void path(char **av)
{
	struct stat st;
	char *slash = "/";
	char *env_path, *cmd, *token, *path;

	env_path = _getenv("PATH");
	cmd = strcat(slash, av[0]);
	token = strtok(env_path, ":");
	while (token)
	{
		path = strcat(token, cmd);
		if (access(path, X_OK) == 0)
		{
			av[0] = path;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(cmd);
}

