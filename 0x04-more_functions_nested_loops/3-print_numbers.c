#include "main.h"

/**
 * print_numbers - print numbers between 0 to 9
 * Return: void
 */
void print_numbers(void)
{
	int c;

	for (c = 0; c <= 9; c++)
	{
		_Putchar((c % 10) + 0);
	}
	_Putchar ('\n');
}
