#include "main.h"

/**
 * print_line - A function that draws a straight line in the terminal.
 *
 * @n: the number of line to draw
 * Return: void
 */
void print_line(int n)
{
	int l;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (l = 0; l < n; l++)
		{
		_putchar(95);
		}
		_putchar('\n');
	}
}

