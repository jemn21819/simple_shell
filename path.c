#include "holberton.h"

/**
* _getenv - parses throught the entire user environment and
* returns the $PATH
* @env: a pointer to the user environment
* @key: the keyword to find in the user environment
*
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
* tokenized path of the user
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
* find_cmd - looks for the PATH, tokenizes the directories in the path.
* then, appends the file from user input to each tokenized directory.
* then, checks to see if the file exists and it has execute permissions.
* lastly, it returns the appended path if it exists or NULL if it doesnt exist
* @cmd: a pointer to the user inputted command
* @env: a pointer to the user environment
*
* Return: appended path if file is executable and exists, NULL if not.
*/

char *find_cmd(char *cmd, char **env)
{
	char *env_path = NULL;
	char **dirs = NULL;
	size_t index;
	char *path = NULL;

	env_path = _getenv(env, "PATH=");
	if (!env_path)
		return (NULL);

	dirs = tokenizer(env_path, ":");

	for (index = 0; dirs && dirs[index]; index++)
	{
		char *curr_path;

		curr_path = append_path(dirs[index], cmd);
		if (access(curr_path, X_OK) == 0)
		{
			path = curr_path;
			break;
		}
		free(curr_path);
	}
	free(dirs);
	free(env_path);

	(void)cmd;
	return (path);
}
