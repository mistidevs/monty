#include "monty.h"

/**
* check_new_line - checks if line only has new line character
* @line: line to check
*
* Return: 0 if success; 1 if fail
*/

int check_new_line(char *line)
{
if (line[0] == '\0' || strlen(line) == 1)
	return (0);

return (1);
}

/**
* unpad - removing white space
* @line: pointer to line to unpad
*
* Return: pointer to unpadded line
*/

char *unpad(char *line)
{
char *new_line, *end, *empty_str;
int i, j = 0;

while (*line && (*line == ' ' || *line == '\n'))
	++line;

end = line + strlen(line) - 1;
while (end > line && (*end == ' ' || *end == '\t'))
	--end;

*(end + 1) = '\0';
if (*line == '\0' || (strlen(line) == 1 && *line == '\n'))
{
	empty_str = malloc(1);
	if (!empty_str)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*empty_str = '\0';
	return (empty_str);
}

new_line = malloc(strlen(line) + 1);
for (i = 0; line[i] != '\0' ; i++)
{
	if (line[i] != ' ' && line[i] != '\n')
	{
		new_line[j++] = line[i];
	}
	else if (i > 0 && line[i - 1] != ' ' && line[i - 1] != '\n')
	{
		new_line[j++] = ' ';
	}
}

new_line[j] = '\0';
return (new_line);
}


/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the iput string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, const char *d) {
int num_words, i, j;
char **words, *token;

num_words = count_words(str, d);
if (num_words == 0)
	return NULL;


words = malloc((num_words + 1) * sizeof(char *));
if (words == NULL)
	return NULL;

token = strtok(str, d);
i = 0;
while (token != NULL)
{
	words[i] = malloc((strlen(token) + 1) * sizeof(char));
	if (words[i] == NULL) {
		for (j = 0; j < i; j++) {
			free(words[j]);
		}
	free(words);
	return NULL;
    	}
	strcpy(words[i], token);
	token = strtok(NULL, d);
	i++;
}

words[i] = NULL;
return words;
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter
 * Return: 1 if true or 0 if false
 */

int is_delim(char c, const char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count
 * @delimiter: separator of words
 *
 * Return: The number of words, or 0 if str is NULL or empty
 */

int count_words(char *str, const char *delimiter)
{
int i, count, in_word;

if (str == NULL || str[0] == '\0')
	return (0);

in_word = 0;
count = 0;
for (i = 0; str[i] != '\0'; i++)
{
	if (str[i] == *delimiter)
		in_word = 0;
	else if (in_word == 0)
	{
		in_word = 1;
		count++;
	}
}

return (count);
}
