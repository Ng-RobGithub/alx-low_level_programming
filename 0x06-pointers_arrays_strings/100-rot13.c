#include "main.h"
#include <stdio.h>

/**
 * rot13 - a function that encodes a string using rot13
 *@s: pointer to string
 *
 * Return: *s
 */
char *rot13(char *s)
{
	int i, j;
	char datal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == datal[j])
			{
				s[i] = datarot[j];
				break;
			}
		}
	}
	return (s);
}
