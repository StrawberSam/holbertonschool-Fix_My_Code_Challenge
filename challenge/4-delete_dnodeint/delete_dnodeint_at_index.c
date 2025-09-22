#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Navigate to the node at the specified index */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	/* If we couldn't reach the index */
	if (current == NULL)
		return (-1);

	/* Update links before freeing */
	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*head = current->next; /* Deleting first node */

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
