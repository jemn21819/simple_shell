#include "holberton.h"
/**
 * _strlen - returns the length of a string.
 * @s: string
 * Return: the length of the string.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp - compares two strings.
 * @s1: string
 * @s2: string
 * Return: 1 if strings are different, 0 if not.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}

	if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * _strncmp - compares two strings up to n bytes.
 * @s1: string.
 * @s2: string.
 * @n: Number of chars to compare.
 * Return: 1 if strings are different, 0 if not.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 || *s1 == *s2)
	{
		return (0);
	}
	return (1);
}
/**
 * _strdup - duplicates a string.
 * @s1: string
 * Return: the newly duplicated string.
 */
char *_strdup(char *s1)
{
	int len, i = 0;
	char *s2;

	len = _strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
	{
		_printf("Error: strdup->malloc\n");
		return (NULL);
	}

	while (i <= len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
/**
 * _strcat - concatenates two strings.
 * @dest: destination string.
 * @src: source string.
 * Return: the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, len;

	len = _strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
