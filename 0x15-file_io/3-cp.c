#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * error_exit - print error message and exits with the program code
 * @msg: Error message to be printed
 * @code: Exit code
 */
void error_exit(const char *msg, int code)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * cp_file - Copy content of file
 * @file_from: Name of source file
 * @file_to: Name of destination file
 */
void cp_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit("Error: Can't read from file", 98);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error_exit("Error: Can't write to file", 99);

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			error_exit("Error: Can't write to file", 99);
		}
	}

	if (bytes_read == -1)
		error_exit("Error: Can't read from file", 98);

	if (close(fd_from) == -1)
		error_exit("Error: Can't close fd", 100);

	if (close(fd_to) == -1)
		error_exit("Error: Can't close fd", 100);
}

/**
 * main - Entry point of program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, or the error code if code fails
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	cp_file(argv[1], argv[2]);

	return (0);
}

