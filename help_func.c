#include "holberton.h"
/**
 * _strlen - returns the length of a string.
 * @s: string to find the length of.
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
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * Return: difference of s1 and s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if ((s1[i] > s2[i]) || (s1[i] < s2[i]))
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strchr - locates a character in a string.
 * @s: pointer to a string.
 * @c: character to be located.
 * Return: s + x.
 */

char *_strchr(char *s, char c)
{
	int x;

	x = 0;
	while (s[x] != c && s[x] != '\0')
	{
		x++;
	}
	if (s[x] == '\0' && s[x] != c)
	{
		return (0);
	}
	return (s + x + 1);
}


/**
 * _strstr - Function that looks for a substring.
 * @src: pointer to source string
 * @sub: pointer to substring to look
 * Return: src or 0
 */

char *_strstr(char *src, char *sub)
{
	int x;
	int y;

	x = 0;
	while (src[x])
	{
		y = 0;
		while (sub[y])
		{
			if (src[x + y] != sub[y])
			{
				break;
			}
			y++;
		}
		if (!sub[y])
		{
			return (src + x + y);
		}
		x++;
	}
	return (0);
}



/**
 * str_concat - concatenates two strings.
 * @s1: string
 * @s2: string
 * Return: the whole concatenated string.
 */
char *str_concat(char *s1, char *s2)
{
	char *array;
	int size1 = 0, size2 = 0, i = 0;

	if (!s1)
		size1 = 0;
	else
	{
		for (size1 = 0; s1[size1]; size1++)
		{}
	}
	if (!s2)
		size2 = 0;
	else
	{
		for (size2 = 0; s2[size2]; size2++)
		{}
	}
	array = malloc((size1 + size2 + 1) *  sizeof(char));
	if (!array)
		return (0);
	for (i = 0; i < (size1 + size2); i++)
	{
		if (i < size1)
		{
			array[i] = *s1;
			s1++;
		}
		else if (i < (size1 + size2))
		{
			array[i] = *s2;
			s2++;
		}
	}
	array[i] = '\0';
	return (array);
}
