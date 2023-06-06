#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of the linked list.
 * @head: Pointer to the original linked list.
 * @str: The string to add to the new node.
 *
 * Return: The address of the new node, or NULL if it fails.
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;

    if (head == NULL || str == NULL)
        return (NULL);

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->len = _strlen(str);
    new_node->next = *head;

    *head = new_node;

    return (new_node);
}

/**
 * _strlen - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return (len);
}

