#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the linked list.
 * @idx: Index where the new node should be added.
 * @n: Value to be stored in the new node.
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	while (count < idx - 1)
	{
		if (temp == NULL)
		{
			free(new_node);
			return (NULL);
		}
		temp = temp->next;
		count++;
	}

	new_node->next = temp->next;
	new_node->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = new_node;

	return (new_node);
}
