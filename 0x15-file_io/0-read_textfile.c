#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Name of the file to be read
 * @letters: Number of letters it should read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buffer[1024];
	ssize_t bytes_read, total_bytes = 0;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	while (letters > 0 && (bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			close(fd);
			return (0);
		}

		letters -= bytes_written;
		total_bytes += bytes_written;
	}

	close(fd);
	return (total_bytes);
}

