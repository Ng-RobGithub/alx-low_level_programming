#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx = 0;
	int first = 1;
	hash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (idx = 0; idx < ht->size; idx++)
	{
		node = ht->array[idx];
		while (node != NULL)
		{
			if (first)
			{
				printf("'%s': '%s'", node->key, node->value);
				first = 0;
			}
			else
			{
				printf(", '%s': '%s'", node->key, node->value);
			}
			node = node->next;
		}
	}
	printf("}\n");
}
