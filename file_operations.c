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

/**
* replace_double_newline - repacing to new line chars
* in a row with a null byte
* @str: string to check
*
* Return: string after alteration
*/

char *replace_double_newline(char *str)
{
char *filtered;
int i = 0, j;

if (str[i] == '\n')
	return (NULL);

while (str[i] != '\0')
{
	if (str[i] == '\n' && str[i + 1] == '\n')
	{
		filtered = malloc((i + 1) * sizeof(char));
		if (filtered == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			return (NULL);
		}
		for (j = 0; j < i; j++)
			filtered[j] = str[j];
		filtered[i] = '\0';
		free(str);
		return (filtered);
	}
	i++;
}

return (str);
}
