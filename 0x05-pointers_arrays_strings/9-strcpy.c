#include "main.h"

/**
 * _strcpy - a function that copies the string pointed to by src
 * including the terminating null byte (\0),
 *
 * @dest: destination
 * @src: source
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (*(src + len) != '\0')
	{
		*(dest + len) = *(len + src);
		len++;
	}

	*(dest + len) = '\0';

	return (dest);
}
