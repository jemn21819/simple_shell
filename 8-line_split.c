#include "holberton.h"
/**
 * line_split - splits a string into tokens (arguments).
 * @line: string to split.
 * Return: an array of tokens (arguments).
 */
char **line_split(char *line)
{
	char **token_array, *token;
	int len, commands, flag, i;

	len = _strlen(line);
	line[len - 1] = '\0';

	commands = 0;
	flag = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			flag = 1;

		if ((flag && line[i + 1] == ' ') || (flag && line[i + 1] == '\0'))
		{
			commands++;
			flag = 0;
		}
		i++;
	}
	if (commands == 0)
		return (NULL);

	token_array = malloc((sizeof(char *)) * (commands + 1));
	if (token_array == NULL)
		return (NULL);

	token = strtok(line, " ");
	i = 0;
	len = 0;
	while (token != NULL)
	{
		token_array[i] = malloc(_strlen(token) + 1);
		if (token_array[i] == NULL)
		{
			free_pointers(token_array);
			return (NULL);
		}

		len = _strlen(token);
		_strncpy(token_array[i], token, len + 1);
		token = strtok(NULL, " ");
		i++;
	}
	token_array[i] = NULL;
	return (token_array);
}
