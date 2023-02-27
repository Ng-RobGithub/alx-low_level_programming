#include "main.h"

/**
 * print_diagonal - A function that draws a diagonal line on the terminal.
 *
 * @n: the number of diagonal to draw
 * Return: void
 */
void print_diagonal(int n)
{
	int d, g;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (d = 0; d <= n; d++)
		{
			for (g = 0; g < d; g++)
			{
				_putchar(' ');
			}
			_putchar('\\');
		}
		_putchar ('\n');
	}
}
