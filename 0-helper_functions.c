#include "holberton.h"
/**
 * _strlen - returns the length of a string.
 * @s: string to find the length of.
 * Return: the length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * _strcpy - copies the src string to dest, up to n bytes.
 * @dest: destination to copy to.
 * @src: source to copy from.
 * @n: amount of bytes to copy.
 * Return: pointer to newly copied string.
 */
char *_strcpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - duplicates a string.
 * @str: string to be duplicated.
 * Return: the newly duplicated string.
 */
char *_strdup(char *str)
{
	char *new, *dup;
	int len = 0;

	len = _strlen(str);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);

	dup = new;
	while (*str)
	{
		*dup = *str;
		dup++;
		str++;
	}
	*dup = '\0';

	return (dup);
}
/**
 * _strcmp - compares two strings.
 * @s1: string to compare.
 * @s2: string to compare.
 * Return: 0 if strings are equal or 1 if not.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
