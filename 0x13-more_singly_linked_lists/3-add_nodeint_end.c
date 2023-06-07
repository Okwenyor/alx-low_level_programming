#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Pointer to the head of the list.
 * @n: The value to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_value, *temp;

	new_value = malloc(sizeof(listint_t));
	if (new_value == NULL)
		return (NULL);

	new_value->n = n;
	new_value->next = NULL;

	if (*head == NULL)
	{
		*head = new_value;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new_value;
	}

	return (new_value);
}

