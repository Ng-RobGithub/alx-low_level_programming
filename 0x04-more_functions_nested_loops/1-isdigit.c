#include "main.h"

/**
 * _isdigit - a function that checks for a digit (0 through 9)
 * @c: input number
 * Return: 1 if it is a number (0 to 9), else 0
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
