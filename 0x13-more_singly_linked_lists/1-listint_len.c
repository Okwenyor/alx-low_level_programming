#include "lists.h"
#include <stdio.h>
/**
 * listint_len - Returns the number of elements in a listint_t list.
 * @h: Pointer to the first node of the list.
 *
 * Return: the number of elements in a linked list
 */
size_t listint_len(const listint_t *h);
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}

	return (count);
}

