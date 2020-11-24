#include "holberton.h"

/**
 * set_mem - fills memory with a constant char
 * @mem: Memory initialize.
 * @byte: Constant byte.
 * @n: Number of bytes to initialize.
 * Return: Void
 */
void set_mem(void *mem, int byte, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		*((char *)mem + i) = byte;
	}
}
