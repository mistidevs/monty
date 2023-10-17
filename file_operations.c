#include "monty.h"

/**
* open_file - open, read and save a file to a char *pointer
* @filename: pointer to filename
*
* Return: pointer with file contents
*/

char *open_file(char *filename)
{
int fd;
char *buffer;
long file_size;

fd = open(filename, O_RDONLY);
if (fd == -1)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

file_size = lseek(fd, 0, SEEK_END);
if (file_size == -1)
{
	perror("lseek");
	return (NULL);
}
lseek(fd, 0, SEEK_SET);

buffer = (char *)malloc(file_size + 1);
if (buffer == NULL)
{
	fprintf(stderr, "Error: malloc failed");
	return (NULL);
}

if (read(fd, buffer, file_size) == -1)
{
	perror("read");
	return (NULL);
}
buffer[file_size] = '\0';

if (close(fd) == -1)
{
	perror("close");
	return (NULL);
}

return (buffer);
}
