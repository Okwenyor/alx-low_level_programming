#ifndef _UNIQUE_LINKED_LIST_H_
#define _UNIQUE_LINKED_LIST_H_

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/**
 * _strlen - calculate length of the string
 * @s: input the string
 *
 * Return: length of the string
 */
int _strlen(const char *s);

/**
 * print_list - Prints all elements of a linked list
 * @h: pointer to the head node
 *
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h);

/**
 * list_len - calculates the number of elements in a linked list
 * @h: pointer to the first node
 *
 * Return: the number of nodes in the list
 */
size_t list_len(const list_t *h);

/**
 * add_node - Add a new node at the beginning of a linked list
 * @head: pointer to the pointer of the first node
 * @str: String to be stored in the new node
 *
 * Return: the address of the new node, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str);

/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: Pointer to the pointer of the head node
 * @str: String to be stored in the new node
 *
 * Return: the address of the new node or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str);

/**
 * free_list - Frees a linked list
 * @head: Pointer to the head node
 */
void free_list(list_t *head);

#endif /* _UNIQUE_LINKED_LIST_H_ */

