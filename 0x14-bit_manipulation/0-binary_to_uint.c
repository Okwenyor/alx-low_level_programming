#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: Pointer to binary string.
 *
 * Return: The converted number, or 0 if there is an invalid input.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int converted_num = 0;
	unsigned int i = 0;

	if (b == NULL)
		return (0);

	while (b[i])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		converted_num = (converted_num << 1) + (b[i] - '0');
		i++;
	}

	return (converted_num);
}

