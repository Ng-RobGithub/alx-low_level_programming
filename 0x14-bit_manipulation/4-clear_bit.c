#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0, at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 on success, -1 if it fails.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int g;

	if (index > 63)
		return (-1);

	g = 1 << index;

	if (*n & g)
		*n ^= g;

	return (1);
}
