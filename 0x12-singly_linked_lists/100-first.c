#include <stdio.h>
#include "lists.h"

/**
 * show_initial_message - prints message before the main function is executed
 *
 * Return: void
 */
void __attribute__((constructor)) show_initial_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

