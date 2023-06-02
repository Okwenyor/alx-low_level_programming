#ifndef _UNIQUE_LINKED_LIST_H_
#define _UNIQUE_LINKED_LIST_H_

/**
* @len: the length of the string
* struct list_s - singly linked list node
* @next: pointer to the next node
*  struct node_t - Structure representing a node in a linked list
*
*Description: the singly linked list structure for node
*/
typedef struct node_t
{
	char *str;
	unsigned int len;
	struct node_t*next;
} node_t;

/**
 * _strlen - calculate length of the string
 * @s: input the string
 *
 * Return: is length of the string
 */
int _strlen(const char *s);

/**
 * print_list - Prints all elements of a linked list
 * @h: pointer to the head node
 *
 * Return: the number of nodes in a list
 */
size_t print_list(const node_t *h);

/**
 * list_len - calculates the number of elements in a linked list
 * @h: pointer to the first node
 *
 * Return: the number of nodes in the list
 */
size_t list_len(const node_t *h);

/**
 * add_node - Add a new node at the beginning of a linked list
 * @head: pointer to the first node
 * @str: String to be stored in the new node
 *
 * Return: the address of the new node, or NULL on failure
 */
node_t *add_node(node_t **head, const char *str);

/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: Pointer to the head node
 * @str: String to be stored in the new node
 *
 * Return: the address of the new node or NULL on failure
 */
node_t *add_node_end(node_t **head, const char *str);

void free_list(node_t *head);

#endif /* _UNIQUE_LINKED_LIST_H_

