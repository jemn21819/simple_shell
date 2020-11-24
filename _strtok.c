#include "holberton.h"
/**
 * cmd_len - finds the number of commands in the string
 * @s: string to find the commands
 * Return: number of commands, unsigned int
 */

unsigned int cmd_len(char *s)
{
	unsigned int cmd, i, flag;

	flag = 0;
	cmd = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			flag = 1;

		if ((flag && s[i + 1] == ' ') || (flag && s[i + 1] == '\0'))
		{
			++cmd;
			flag = 0;
		}
		++i;
	}
	return (cmd);
}
/**
 * arr_strtok - creates a double pointer array that holders pointers
 * to each string from the command line
 * @str: commands from the terminla
 * Return: double pointer array of pointers commands interpret and execute
 */
char **arr_strtok(char *str)
{
	char **args;
	char *token;
	unsigned int len;
	int i;

	str[_strlen(str) - 1] = '\0';
	len = cmd_len(str);
	if (len == 0)
		return (NULL);

	args = malloc((sizeof(char *)) * (len + 1));
	if (args == NULL)
		return (NULL);
	i = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		args[i] = malloc(_strlen(token) + 1);
		if (args[i] == NULL)
		{
			free_dptr(args);
			return (NULL);
		}
		_strncpy(args[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		++i;
	}
	args[i] = NULL;
	return (args);
}
