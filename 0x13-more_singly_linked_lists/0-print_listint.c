#include "lists.h"
#include <stdio.h>
/**
 * print_listint - Print all elements of listint_t list.
 * @h: Pointer to the first node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
