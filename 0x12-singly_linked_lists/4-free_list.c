#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list
 * @head: Pointer to the head node
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;

		if (current->str != NULL)
			free(current->str);
		free(current);
	}
}

