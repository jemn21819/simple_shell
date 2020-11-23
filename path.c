#include "holberton.h"


/**
* _getenv - searches the environment for a string
* @var: keyword to look for
* Return: pointer to value of keyword variable
*/

char *_getenv(char *var)
{
	char *token;
	int i;

	i = 0;
	while (environ[i])
	{
		if (_strcmp(var, environ[i]) == 0)
		{
			token = _strstr(environ[i], var);
			if (token[0] == '=')
			{
				token = _strchr(environ[i], '=');
				return (token);
			}
		}
		i++;
	}
	return (0);
}
/**
 * path - Find the path to a command.
 * @argv: command to look for a path.
 * Return: A pointer created with malloc.
 */

void path(char **argv)
{
	struct stat st;
	char *slsh = "/";
	char *env_path, *command, *token, *path;

	env_path = _getenv("PATH");
	command = str_concat(slsh, argv[0]);
	token = strtok(env_path, ":");
	while (token)
	{
		path = str_concat(token, command);
		if (stat(path, &st) == 0)
		{
			argv[0] = path;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(command);
}

/**
* _env - print enviroment
* Return: nothing
*/

void _env(void)
{
	char **ep;

	ep = environ;
	while (*ep)
	{
		write(1, *ep, _strlen(*ep));
		write(1, "\n", 1);
		ep++;
	}
}
