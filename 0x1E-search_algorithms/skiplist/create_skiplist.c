#include <stdlib.h>
#include <math.h>
#include "../search_algos.h"

void free_skiplist(skiplist_t *list);

/**
 * init_express - Initializes the express lane of the linked list
 *
 * @list: Pointer to the head node of the list
 * @size: Number of nodes in the list
 */
void init_express(skiplist_t *list, size_t size)
{
	const size_t step = sqrt(size);
	size_t i;
	skiplist_t *save;

	for (save = list, i = 0; i < size; ++i, list = list->next)
	{
		if (i % step == 0)
		{
			save->express = list;
			save = list;
		}
	}
}

/**
 * create_skiplist - Create a singly linked list
 *
 * @array: Pointer to the array used to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	skiplist_t *list = NULL;
	size_t save_size = size;

	for (size_t i = 0; i < size; i++)
	{
		skiplist_t *node = malloc(sizeof(*node));

		if (node == NULL)
		{
			free_skiplist(list);
			return (NULL);
		}
		node->n = array[i];
		node->index = i;
		node->express = NULL;
		node->next = list;
		list = node;
	}
	init_express(list, save_size);
	return (list);
}
