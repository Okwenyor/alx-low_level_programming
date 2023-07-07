#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of the number
 * @n: The number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1;
	int bits = sizeof(unsigned long int) * 8;
	int index;

	for (index = bits - 1; index >= 0; i--)
	{
		if ((n >> index) & mask)
			_putchar('1');
		else
			_putchar('0');
	}
}

