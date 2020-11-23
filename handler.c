#include "holberton.h"

/**
 * handler - handles the ctrl+c signal.
 * @signal: integer that represents the signal.
 * Return: nothing.
 */

void handler(__attribute__((unused))int signal)
{
	write(1, "\n$ ", 3);
}
