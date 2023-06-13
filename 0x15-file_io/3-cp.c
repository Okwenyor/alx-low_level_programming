#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Print error message and exit with a specified code
 * @code: Exit code
 * @message: the error message
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * main - Entry point of the code program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, non-zero when faied
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
		error_exit(98, "Error: Can't read from file %s", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to %s", argv[2]);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			error_exit(99, "Error: Can't write to %s", argv[2]);
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file %s", argv[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d", fd_to);

	return (0);
}

