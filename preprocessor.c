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

char **strtow(char *str, const char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!d)
		d = " ";
	numwords = count_words(str, d);
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; i < (int)strlen(str); i++)
	{
		if (is_delim(str[i], d))
		{
			if (i > 0 && is_delim(str[i - 1], d))
			{
				s[j] = malloc(2 * sizeof(char));
				if (!s[j])
				{
					for (k = 0; k < j; k++)
						free(s[k]);
					free(s);
					return (NULL); }
				s[j][0] = ' ', s[j][1] = '\0', j++;
			}
		}
		else
		{
			k = 0;
			while (!is_delim(str[i + k], d) && str[i + k])
				k++;
			s[j] = malloc((k + 1) * sizeof(char));
			if (!s[j])
			{
				for (k = 0; k < j; k++)
					free(s[k]);
				free(s);
				return (NULL);
			}
			for (m = 0; m < k; m++)
				s[j][m] = str[i++];
			s[j][m] = '\0';
			j++;
		}
	}
	s[j] = NULL;
	return (s);
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
