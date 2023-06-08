#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to a pointer to the first node.
 *
 * Return: The data (n) stored in the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *current;

	if (head != NULL && *head != NULL)
	{
		current = *head;
		data = current->n;
		*head = current->next;
		free(current);
	}

	return (data);
}

