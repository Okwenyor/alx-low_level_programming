#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all elements of list
 * @head: linked list
 *
 * Return: Number of nodes
 */
size_t print_list(const _list_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		if (head->list == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", head->length, head->data);

		head = head->next;
		count++;
	}

	return count;
}
