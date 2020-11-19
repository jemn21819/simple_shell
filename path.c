#include "holberton.h"

/**
* _getenv - parses entire user environment looking for $PATH
* @env: pointer to the user environment
* @key: the keyword to find in the user environment
* Return: User PATH on success
*/

char *_getenv(char **env, char *key)
{
	size_t i;

	for (i = 0; env && env[i]; i++)
	{
		if (_str_n_cmp(env[i], key, _strlen(key)) == 0)

			return (_strdup(env[i] + _strlen(key)));
	}
	return (NULL);
}

/**
* append_path - appends the file from stdin to the
* tokenized path 
* @dir: pointer to a single directory from the user PATH
* @file: pointer to the file from stdin
* Return: the appended path (directory + file)
*/

char *append_path(const char *dir, const char *file)
{
	char *path;
	size_t path_len;
	size_t dir_len = _strlen(dir);
	size_t file_len = _strlen(file);

	path_len = dir_len + 1 + file_len;
	path = malloc(path_len + 1);

	_strcpy(path, dir, dir_len);
	path[dir_len] = '/';
	_strcpy(path + dir_len + 1, file, file_len);
	path[path_len] = 0;

	return (path);
}

/**
* find_cmd - looks for PATH tokenizes the directories in the path
* appends the fileinput to each tokenized directory.
* @cmd: pointer to the user inputted command
* @env: pointer to the user environment
* Return: appended path if file is executable and exists, NULL if not.
*/

char *find_cmd(char *cmd, char **env)
{
	char *env_path = NULL;
	char **dir = NULL;
	size_t index;
	char *path = NULL;

	env_path = _getenv(env, "PATH=");
	if (!env_path)
		return (NULL);

	dir = tokenizer(env_path, ":");

	for (index = 0; dir && dir[index]; index++)
	{
		char *cmd_path;

		cmd_path = append_path(dir[index], cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			path = cmd_path;
			break;
		}
		free(cmd_path);
	}
	free(dir);
	free(env_path);
	return (path);
}

