#include "holberton.h"

/**
 * get_delim - check for delimineter in a string
 * @c: characters to compare
 * @delim: pointer to delimeter list
 * Return: 1 for delimeter or 0 if not
 */

char get_delim(const char c, const char *delim)
{
	unsigned char index = 0;

	while (delim[index])
	{
		if (delim[index] == c)
			return (1);
		index++;
	}
	return (0);
}

/**
 * tok_counter - count tokens from getline.
 * @line: pointer to string in getline
 * @delim: pointer to delimeters string to separete
 * Return: number of tokens
 */

size_t tok_counter(const char *line, const char *delim)
{
	size_t count = 0;
	int index = 0;

	while (line[index])
	{
		while (get_delim(line[index], delim))
			index++;
		if (line[index] == '\0')
		{
			break;
		}
		count++;
		while (!get_delim(line[index], delim) && line[index] != '\0')
			index++;
	}
	return (count);
}

/**
* tok_string - tokenizes a string by a delimeter
* @arstr: a pointer to array that hold the tokenized strings
* @line: a pointer to the string
* @delim: a pointer to the delimeter
*/

void tok_string(char **arstr, char *line, const char *delim)
{

	char *token;
	size_t index = 0;

	token = strtok(line, delim);
	while (token)
	{
		arstr[index] = token;
		index++;
		token = strtok(NULL, delim);
	}
	arstr[index] = NULL;
}

/**
* tokenizer - allocates memory for a given array.
* and fill array with tokens
* @line: line passed from getline
* @delim: a string of delimeters
*
* Return: array of tokenized string
*/

char **tokenizer(char *line, const char *delim)
{
	size_t n;
	char **arr_str;

	n = tok_counter(line, delim);
	if (n == 0)
		return (NULL);

	arr_str = malloc(sizeof(*arr_str) * (n + 1));
	if (!arr_str)
	{
		free(arr_str);
		_printstr("malloc failed");
		exit(EXIT_FAILURE);
	}
	tok_string(arr_str, line, delim);

	return (arr_str);
}
