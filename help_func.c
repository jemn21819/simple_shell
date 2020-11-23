#include "holberton.h"
/**
 * _strlen - returns the length of a string.
 * @s: string to find the length of.
 * Return: the length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/**
 * _strcmp - compares two strings.
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 * Return: difference of s1 and s2.
 */
int _strcmp(char *s1, char *s2)
{
	int len = 0;

	while (s1[len])
	{
		if ((s1[len] > s2[len]) || (s1[len] < s2[len]))
		{
			return (s1[len] - s2[len]);
		}
		len++;
	}
	return (0);
}
/**
 * _chr_locate - locates a character in a string.
 * @str: pointer to a string.
 * @c: character to be located.
 * Return: s + x.
 */
char *_chr_locate(char *str, char c)
{
	int x = 0;

	while (str[x] != c && str[x] != '\0')
	{
		x++;
	}
	if (str[x] == '\0' && str[x] != c)
	{
		return (0);
	}
	return (str + x + 1);
}
/**
 * _sublook - Function that looks for a substring.
 * @src: pointer to source string
 * @substr: pointer to substring to look
 * Return: src or 0
 */
char *_sublook(char *src, char *substr)
{
	int x = 0;
	int y;

	while (src[x])
	{
		y = 0;
		while (substr[y])
		{
			if (src[x + y] != substr[y])
			{
				break;
			}
			y++;
		}
		if (!substr[y])
		{
			return (src + x + y);
		}
		x++;
	}
	return (0);
}
/**
 * _strcat - concatenates two strings.
 * @dest: string
 * @src: string
 * Return: the whole concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	char *array;
	int i, size1, size2;

	if (!dest)
		size1 = 0;
	else
	{
		for (size1 = 0; dest[size1]; size1++)
		{}
	}
	if (!src)
		size2 = 0;
	else
	{
		for (size2 = 0; src[size2]; size2++)
		{}
	}
	array = malloc((size1 + size2 + 1) *  sizeof(char));
	if (!array)
		return (0);

	for (i = 0; i < (size1 + size2); i++)
	{
		if (i < size1)
		{
			array[i] = *dest;
			dest++;
		}
		else if (i < (size1 + size2))
		{
			array[i] = *src;
			src++;
		}
	}
	array[i] = '\0';
	return (array);
}
