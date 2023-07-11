#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

/* _putchar: writes a character to stdout */
int _putchar(char c);

/*
 * read_textfile: reads a text file and prints its contents to stdout
 * letters: number of letters to be read and printed
 * Returns: the actual number of letters it read and print or 0 for error
 */
ssize_t read_textfile(const char *filename, size_t letters);

/*
 * create_file: creates a file and writes the given text content to it
 * filename: the name of the file to create
 * text_content : a NULL terminated string to write to the file
 * Return : 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content);

/*
 * append_text_to_file: appends the given text content to an existing file
 * filename : the name of the file
 * text_content : NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
