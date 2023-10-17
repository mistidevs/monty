#include "monty.h"

/** unpad - removing white space
* @line: pointer to line to unpad
*
* Return: pointer to unpadded line
*/

char *unpad(char *line)
{
char *unpadded = line;
int i = 0, j = 0;

if (line[i] == ' ')
{
	while (line[i] == ' ')
		i++;
}

if (line[i] != " ")
{
	while (line[i] != ' ')
	{
		unpadded[j] = line[i];
		i++, j++;
	}
	if (line[i] == '\n' || line[i] == '\0')
		return (NULL);
	unpadded[j] = line[i];
	i++, j++;
	if (line[i] == " ")
	{
		while (line[i] == ' ')
		{
			if (line[i] == '\n' || line[i] == '\0')
				return (NULL);
			i++, j++;
		}
	}
	while (line[i] != ' ' || line[i] != '\n' || line[i] != '\0')
	{
		unpadded[j] = line[i];
		i++, j++;
	}
	unpadded[j] = '\0';
}

return (unpadded);
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
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
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
		s[j][m] = 0;
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

int is_delim(char c, char *delim)
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
