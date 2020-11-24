#include "holberton.h"

/**
 * parse_path - Converts a string into tokens.
 * @str: String to be tokenized.
 * @delim: Delimiter.
 * Return: Tokens (char **)
 */

char **parse_path(char *str, char delim)
{
	int token_count, x, y;
	char **tokens;
	char *token;

	token_count = count_words(str, delim);
	tokens = malloc(sizeof(char *) * (token_count + 1));
	if (tokens == NULL)
		return (NULL);
	x = 0;
	y = 0;
	while (x < token_count)
	{
		if (str[y] != delim && str[y] != '\0')
		{
			tokens[x] = malloc(sizeof(char) *
				(count_chars(&(str[y]), delim) + 1));
			if (tokens[x] == NULL)
				return (NULL);
			token = tokens[x];
			while (str[y] != delim && str[y] != '\0')
			{
				*token++ = str[y];
				y++;
			}
			*token = '\0';
			while (str[y] == delim && str[y] != '\0')
				y++;
			x++;
		}
		else
			y++;
	}
	tokens[token_count] = (NULL);
	return (tokens);
}

/**
 * count_chars - Counts chars in string.
 * @str: String to be tokenized.
 * @delim: Delimiter.
 * Return: Count (int).
 */

int count_chars(char *str, char delim)
{
	int count;

	count = 0;
	while (*str != delim && *str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

/**
 * count_words - Counts words in a string.
 * @str: String to be tokenized.
 * @delim: Delimiter.
 * Return: Count (int).
 */

int count_words(char *str, char delim)
{
	int token_count;

	token_count = 0;
	while (*str != '\0')
	{
		if (*str != delim)
		{
			token_count++;
		}
		while (*str != delim && *str != '\0')
		{
			str++;
		}
		while (*str == delim && *str != '\0')
		{
			str++;
		}
	}
	return (token_count);
}
