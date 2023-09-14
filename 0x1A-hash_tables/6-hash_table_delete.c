#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *node, *temp;

	if (ht == NULL)
		return;

	for (idx = 0; idx < ht->size; idx++)
	{
		node = ht->array[idx];
		while (node != NULL)
		{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}

	free(ht->array);
	free(ht);
}
