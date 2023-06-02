#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - it counts the number of elements in the linked list
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of elements in linked list.
 */
size_t list_len(const list_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		head = head->next;
		count++;
	}

	return (count);
}

