#include "main.h"
#include <fcntl.h>
#include <unistd.h>

int create_file(const char *filename, char *text_content)
{
int fd, i;
    ssize_t text_len = 0;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[text_len] != '\0')
            text_len++;

i = write(fd, text_content, text_len);
        if (i == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

