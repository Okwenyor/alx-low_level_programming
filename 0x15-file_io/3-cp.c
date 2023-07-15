#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints the error message and exits with the code given
 * @message: Error message to print
 * @file_name: File name to include in error message
 * @exit_code: Exit code to use
 */
void error_exit(const char *message, const char *file_name, int exit_code)
{
if (dprintf(STDERR_FILENO, "%s %s\n", message, file_name) < 0)
{
dprintf(STDERR_FILENO, "Error: Failed to print error message\n");
}
exit(exit_code);
}

/**
 * cp_file - copies content of file_from to file_to
 * @file_from: the source file to be copied
 * @file_to: destination file to copy to
 */
void cp_file(const char *file_from, const char *file_to)
{
int fd_from, fd_to;
ssize_t rdlen, wrlen;
char buffer[BUFFER_SIZE];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_exit("Error: Can't read from file", file_from, 98);

fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd_to == -1)
{
close(fd_from);
error_exit("Error: Can't write to", file_to, 99);
}

while ((rdlen = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
wrlen = write(fd_to, buffer, rdlen);
if (wrlen == -1)
{
close(fd_from);
close(fd_to);
error_exit("Error: Can't write to", file_to, 99);
}
}

if (rdlen == -1)
{
close(fd_from);
close(fd_to);
error_exit("Error: Can't read from file", file_from, 98);
}

if (close(fd_from) == -1)
error_exit("Error: Can't close fd", "FD_FROM", 100);

if (close(fd_to) == -1)
error_exit("Error: Can't close fd", "FD_TO", 100);
}

/**
 * main - entry point of program
 * @argc: number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 on success, 97 when incorrect number of arguments is passed
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
return (97);
}

cp_file(argv[1], argv[2]);

return (0);
}

