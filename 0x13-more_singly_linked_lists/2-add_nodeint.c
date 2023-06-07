#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Adds a new node at the beginning of the listint_t list.
 * @head: Pointer to the first node of the list.
 * @n: The value to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_value = malloc(sizeof(listint_t));

	if (new_value == NULL)
		return (NULL);

	new_value->n = n;
	new_value->next = *head;
	*head = new_value;

	return (new_value);
}

