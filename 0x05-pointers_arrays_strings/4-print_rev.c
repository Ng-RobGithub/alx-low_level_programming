#include "main.h"

/**
 * print_rev - a function that prints a string,
 * in reverse, followed by a new line.
 * @s: string to be printed
 */
void print_rev(char *s)
{
	int i, j;

	j = 0;

	while (s[j] != '\0')
		j++;

	for (i = j - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	_putchar('\n');

}
