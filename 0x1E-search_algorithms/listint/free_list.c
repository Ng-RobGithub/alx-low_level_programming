#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_list - Deallocates a singly linked list
 *
 * @list: Pointer to the linked list to be freed
 */
void free_list(listint_t *list)
{
	listint_t *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
