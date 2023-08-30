#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * dlistint_len - Function that prints the number o elements in a dlistintlist
 * @h: header
 * Return: lenght of the linked lisyt
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		num++;
		h = h->next;
	}
	return (num);
}

