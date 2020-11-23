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

/**
 * handler - handles the ctrl+c signal.
 * @signal: integer that represents the signal.
 * Return: nothing.
 */

void handler(int signal)
{
	(void)signal;

	_printstr("\n$ ");
}
