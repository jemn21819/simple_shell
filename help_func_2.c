#include "holberton.h"

/**
 * _strcat - concatenates two strings.
 * @dest: string
 * @src: string
 * Return: the whole concatenated string.
 */

char *_strcat(char *dest, char *src)
{

	int i = 0, j;

	while (dest[i] != '\0')
	{
		i++;
	}

	for (j = 0; src[j] != '\0'; j++)
	{

		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _atoi - converts from char to int
 * @str: string to convert.
 * Return: converted integer.
 */
int _atoi(char *str)
{
	int num, i = 0, sign = 1;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
}
