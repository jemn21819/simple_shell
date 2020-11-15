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
 * _strcpy - copies the string pointed to by src, including the terminating
 *           null byte to the buffer pointed to by dest.
 * @dest: destination to copy src.
 * @src: pointer to the src string.
 * @n: size of string to copy.
 * Return: nothing.
 */
void _strcpy(char *dest, char *src, size_t n)
{
	size_t i = 0;

	while (i < n && dest && src)
	{
		dest[i] = src[i];
		i++;
	}
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
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * Return: difference of s1 and s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/**
 * _str_n_cmp - compares two strings up to the byte size n
 * @s1: a pointer to the first string
 * @s2: a pointer to the second string
 * @n: the byte size of the string to compare
 * Return: the difference of s1 and s2
 */
int _str_n_cmp(char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	return (0);
}
