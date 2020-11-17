#include "holberton.h"

/**
* _printstr - write to print a string
* @str: pointer to the string to print
* Return: string to print
*/

int _printstr(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}
