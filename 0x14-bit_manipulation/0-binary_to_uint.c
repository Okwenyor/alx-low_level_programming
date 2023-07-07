#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer
 * @b: The pointer to the binary string
 *
 * Return: The converted unsigned integer, or 0 if there is an invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int index = 0;

	if (b == NULL)
		return (0);

	while (b[index])
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);
		result = (result << 1) + (b[index] - '0');
		index++;
	}

	return (result);
}

