#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints the error message and exits with the code given
 * @message: Error message to print
 * @exit_code: Exit code to use
 */
void error_exit(const char *message, int exit_code)
{
int v = 0;

while (message[v] != '\0')
v++;

write(STDERR_FILENO, message, v);
exit(exit_code);
}

/**
 * cp_file - copies content of file_from to file_to
 * @file_from: the source file to be copied
 * @file_to: destination file to copy to
 */
void cp_file(const char *file_from, const char *file_to)
{
int fd_from, fd_to, rdlen, wrlen;
char buffer[1024];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_exit("Error: Can't read from file NAME_OF_THE_FILE", 98);

fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd_to == -1)
error_exit("Error: Can't write to NAME_OF_THE_FILE ", 99);

while ((rdlen = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
wrlen = write(fd_to, buffer, rdlen);
if (wrlen == -1)
error_exit("Error: Can't write to  NAME_OF_THE_FILE", 99);
}

if (rdlen == -1)
error_exit("Error: Can't read from file", 98);

if (close(fd_from) == -1)
error_exit("Error: Can't close fd", 100);

if (close(fd_to) == -1)
error_exit("Error: Can't close fd FD_VALUE ", 100);
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
int i;

if (argc != 3)
{
char *usage_msg = "Usage: ";
char *file_from = argv[0];
char *file_to = " file_from file_to\n";

write(STDERR_FILENO, usage_msg, 7);
for (i = 0; file_from[i] != '\0'; i++)
write(STDERR_FILENO, &file_from[i], 1);
write(STDERR_FILENO, file_to, 18);
return (97);
}

cp_file(argv[1], argv[2]);

return (0);
}

