#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Name of the file to be read
 * @letters: Number of letters it should read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0;
    }

    int file = open(filename, O_RDONLY);
    if (file == -1) {
        return 0;
    }

    char *buffer = malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL) {
        close(file);
        return 0;
    }

    ssize_t bytesRead = read(file, buffer, letters);
    if (bytesRead == -1) 
{
        close(file);
        free(buffer);
        return (0);
    }

    ssize_t totalRead = write(STDOUT_FILENO, buffer, bytesRead);
    if (totalRead == -1 || (size_t)totalRead != bytesRead) {
        close(file);
        free(buffer);
        return (0);
    }

totalRead = bytesWritten;
    close(file);
    free(buffer);

    return (totalRead);
}

