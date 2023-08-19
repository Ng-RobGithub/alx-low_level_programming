#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * of a linked list.
 * @head: Pointer to a pointer to the head of the linked list.
 * @index: Index of the node to be deleted.
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (count < index)
	{
		if (temp == NULL)
			return (-1);
		temp = temp->next;
		count++;
	}

	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	free(temp);

	return (1);
}
