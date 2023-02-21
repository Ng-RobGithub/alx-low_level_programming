#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - print a random number
 * Positive or Negative
 * Return: 0
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
		printf("%d is Positive\n", n);
	else if (n < 0)
		printf("%d is Negative\n", n);
	else
		printf("%d is Zero\n", n);
	return (0);
}
