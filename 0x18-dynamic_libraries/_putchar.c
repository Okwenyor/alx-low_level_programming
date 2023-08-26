#include <unistd.h>

/**
 * _putchar - write character to stdout
 * @c: the character to print
 * Return: 1 on success and -1 on failure and erno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
