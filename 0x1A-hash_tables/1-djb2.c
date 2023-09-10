#include "hash_tables.h"

/**
 * hash_djb2 - Hash function implementing the djb2 algorithm
 * @str: The input string to be hashed
 *
 * Description:
 * The djb2 algorithm is a simple and widely-used hash function designed
 * by Daniel J. Bernstein. It is known for its good distribution and speed.
 * This function takes an input string and computes its hash value using
 * the djb2 algorithm.
 *
 * Return: The computed hash value as an unsigned long integer.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381; /* Initial hash value */
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash);
}
