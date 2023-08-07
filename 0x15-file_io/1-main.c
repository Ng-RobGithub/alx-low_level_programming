#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * main - check the code
 *
 * @ac: represents the argument count, which is the number of arguments
 * @av: is an array of strings containing the actual arguments.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int res;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s filename text\n", av[0]);
		exit(1);
	}
	res = create_file(av[1], av[2]);
	printf("-> %i)\n", res);
	return (0);
}
