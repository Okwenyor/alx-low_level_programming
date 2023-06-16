#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Print error message and exit with code specified
 * @code: Exit code
 * @format: Format string for error message
 * @...: Additional arguments for the format string
 *
 * Description: Print error message to stderr and exits with code given
 */
void error_exit(int code, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	fprintf(stderr, "Error: ");
	vfprintf(stderr, format, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(code);
}

/**
 * main - Entry point of the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, non-zero on code failure
 *
 * Description: would copy the content of file_from to file_to.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Can't read from file %s", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Can't write to file %s", argv[2]);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			error_exit(99, "Can't write to file %s", argv[2]);
	}

	if (bytes_read == -1)
		error_exit(98, "Can't read from file %s", argv[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Can't close fd %d", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Can't close fd %d", fd_to);

	return (0);
}

