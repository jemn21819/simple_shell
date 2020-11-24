#include "holberton.h"

/**
 * _putchar - prints a single character.
 * @c: character
 * Return: 1 on success.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _printf - prints a string of characters.
 * @str: string
 * Return: nothing
 */
void _printf(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _itoa - converts from integer to string.
 * @n: integer
 * Return: the converted string.
 */
char *_itoa(int n)
{
	int i = 0, len, negative;
	char *str;

	if (n == 0)
	{
		return ("0");
	}
	else if (n < 0)
	{
		negative = 1;
	}
	else
	{
		negative = 0;
		n = n * -1;
	}

	len = _intlen(n);
	str = malloc(sizeof(char) * (len + negative + 1));
	if (!str)
	{
		return (NULL);
	}

	str[len + negative] = '\0';
	for (i <= len)
	{
		str[len + negative - i] = '0' + (n % 10 * -1);
		n = n / 10;
	}
	if (negative)
	{
		str[0] = '-';
	}
	return (str);
}
/**
 * _atoi - converts from string to integer.
 * @str: string
 * Return: the converted integer.
 */
int _atoi(char *str)
{
	int i = 0, num = 0, sign = 1;

	while (str[i] != '\0')
	{
		if (str[i] == '-' && !num)
		{
			sign = sign * -1;
		}
		else if (str[i] > '9' || str[i] < '0')
		{
			return (0);
		}
		else
		{
			num = (num * 10) + (str[i] - '0');
		}
	}
	return (num * sign);
}
/**
 * _intlen - returns the length of an integer.
 * @n: integer
 * Return: the length of the integer.
 */
int _intlen(int n)
{
	int i = 0;

	while (n <= -1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
