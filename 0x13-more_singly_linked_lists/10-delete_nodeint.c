#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes node at a given position in a list
 * @head: Pointer to the head node of the list
 * @index: Index of the node to be deleted (starting at 0)
 *
 * Return: 1 if deletion succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	listint_t *current = *head;
	unsigned int i;

	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (-1);

	listint_t *temp = current->next;

	current->next = temp->next;
	free(temp);

	return (1);
}

