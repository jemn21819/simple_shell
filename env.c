#include "holberton.h"
/**
 * find_dir- finds the total number of directories in your path
 * @path: the path string
 * Return: number of directories in the path
 */
unsigned int find_dir(char *path)
{
	unsigned int dir, i, flag;

	i = 0, dir = 0, flag = 0;
	while (path[i])
	{
		if (path[i] != ':')
			flag = 1;

		if ((flag && path[i + 1] == ':') || (flag && path[i + 1] == '\0'))
		{
			++dir;
			flag = 0;
		}
		++i;
	}
	return (dir);
}
/**
 * _strncpycmd - copies paths and appens a / + command to each path
 * @dest: destination
 * @src: source
 * @cmd: command to append
 * @n: length of the destination
 * @c: length of the command
 * Return: destination address
 */

char *_strncpycmd(char *dest, char *src, char *cmd, int n, int c)
{
	int i, j;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	/* appends "/" + "command" to the src */
	dest[i] = '/';
	i++;
	for (j = 0; j < c && cmd[j] != '\0'; j++, i++)
		dest[i] = cmd[j];

	dest[i] = '\0';

	return (dest);
}
/**
 * env_var - creates a double pointer array,
 * where it stores each path directory as a single pointer, NULL terminated
 * @cmd: first command that you type in the prompt
 * @environ: the environment variables
 * Return: memory address of the double pointer array
 */

char **env_var(char *cmd, char **environ)
{
	/* cmd is the first command from the shell */
	char **arr_dir;
	char *path_env, *directory;
	unsigned int len, i;
	int dir_len, cmd_len;

	path_env = _getenv("PATH", environ);
	len = find_dir(path_env);
	arr_dir = malloc(sizeof(char *) * (len + 1));
	if (arr_dir == NULL)
		return (NULL);

	i = 0;
	directory = strtok(path_env, ":");
	while (directory != NULL)
	{
		dir_len = _strlen(directory);
		cmd_len = _strlen(cmd);
		/* add 2 to malloc for \0 and extra "/" for the slash to append ls */
		arr_dir[i] = malloc(sizeof(char) * (dir_len + cmd_len + 2));
		if (arr_dir[i] == NULL)
		{
			free_dptr(arr_dir);
			return (NULL);
		}
		_strncpycmd(arr_dir[i], directory, cmd, dir_len, cmd_len);
		++i;
		directory = strtok(NULL, ":");
	}
	arr_dir[i] = NULL;

	return (arr_dir);
}
/**
 * _getenv - gets the environment variable value
 * @key: name of the environment variable you are looking for
 * @environ: the enviroment variables
 * Return: the value associated with the variable
 */

char *_getenv(const char *key, char **environ)
{
	char *env_val;
	char *key_copy;
	unsigned int i, len;

	/* find the length of the argument, then malloc space for it */
	len = _strlen_const(key);
	key_copy = malloc((sizeof(char) * len) + 1);
	if (key_copy == NULL)
		return (NULL);
	/* copy the contents of the name argument to the new variable, key_copy */
	_strncpyconst(key_copy, key, len);
	/*
	 * find the enviroment variable that matches the key_copy variable
	 * assign the value to the value variable and return the address
	 */
	i = 0;
	env_val = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_val, key_copy))
		{
			env_val = strtok(NULL, "\n");
			free(key_copy);
			return (env_val);
		}
		++i;
		env_val = strtok(environ[i], "=");
	}

	free(key_copy);
	return (NULL);
}

/**
 * print_env - prints all of the environment variables to the output
 * @environ: all environment variables for the user
 */

void print_env(char **environ)
{
	unsigned int i, len;

	i = 0;
	while (environ[i])
	{
		/* find the length of each env variable */
		len = _strlen(environ[i]);
		/* write it out the the stdout */
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
