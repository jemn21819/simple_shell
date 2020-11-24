#include "holberton.h"
#define BUFFER 128


/**
 * _env - prints environment variables
 * @env: array of env variables
 * Return: 1.
 */

int _env(char **env)
{
	int i;

	i = 0;
	while (env[i] != '\0')
	{
		_printf(env[i]);
		_printf("\n");
		i++;
	}
	return (1);
}


/**
 * get_env_var_val - get environment variables values.
 * @env_var: environment variable array.
 * Return: environment variable value.
 */

char *get_env_var_val(char *env_var)
{
	size_t len;
	char *env_var_val;
	int i;
	int j;
	int k;

	len = _strlen(env_var);
	env_var_val = malloc(sizeof(char) * BUFFER);
	if (!env_var_val)
	{
		_printf("Error get_env_var_val->malloc\n");
		free(env_var_val);
		return (NULL);
	}

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(env_var, environ[i], len) == 0)
		{
			break;
		}
	}
	for (j = len, k = len; j < BUFFER; j++, k++)
	{
		if (environ[i][k] == '=')
		{
			k++;
		}
		env_var_val[j - len] = environ[i][k];
	}
	return (env_var_val);
}
