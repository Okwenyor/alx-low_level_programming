#include "main.h"
#include <stdio.h>

/**
 * print_binary - print the binary representation of a number
 * @n: number to print in the binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	putchar((n & 1) + '0');
}

