#include "main.h"
#include <stdio.h>

/**
 * print_array - a function that prints n elements of an array of integers,
 *
 * @a: an array
 * @n: number of values to be printed
 */
void print_array(int *a, int n)
{
	int g;

	for (g = 0; g < n; g++)
	{
		printf("%d", a[g]);
		if (g != n - 1)
		printf(" , ");
	}
	printf("\n");
}
