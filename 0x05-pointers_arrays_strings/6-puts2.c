#include "main.h"

/**
 * puts - a function that prints every other character of a string,
 * starting with the first character, followed by a new line.
 * print one character out of two
 *
 * @str: input
 * Return: print
 */
void puts2(char *str)
{

	int c;
	int j = 0;

	while (str[j] != '\0')
	{
		j++;
	}

	for (c = 0; c < j; c += 2)
	{
		_putchar(str[c]);
	}

	_putchar('\n');
}
