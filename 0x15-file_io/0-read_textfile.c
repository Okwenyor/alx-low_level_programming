#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Name of the file to be read
 * @letters: Number of letters it should read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

int fd, rdlen;
char buffer[1024];
size_t total = 0;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
while (total < letters && (rdlen = read(fd, buffer, 1)) > 0)
{
if (write(STDOUT_FILENO, buffer, rdlen) != rdlen)
{
close(fd);
return (0);
}
total++;
}

close(fd);
return (total);
}


