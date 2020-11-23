#include "holberton.h"

/**
 * handler - handles the ctrl+c signal.
 * @signal: integer that represents the signal.
 * Return: nothing.
 */

void handler(int signal)
{
	(void)signal;

	write(STDOUT_FILENO, "\n$ ", 3);
}
