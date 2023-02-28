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
	int c = 0;

	for (; str[c] != '\0' ; c++)
	{
		if ((c % 2) == 0)
			_putchar(str[c]);
		else
			continue;
	}
	_putchar('\n');
}
