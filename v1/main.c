#include "monty.h"

/**
* main - monty interpreter
* @ac: argument counter
* @av: argument vector
*
* Return: suitable integer
*/

int main(int ac, char **av)
{
char *raw, *filter;
char **commands;

if (ac != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

raw = open_file(av[1]);
if (raw == NULL)
	exit(EXIT_FAILURE);

filter = replace_double_newline(raw);
if (filter == NULL)
{
	free(raw);
	return (0);
}
commands = strtow(filter, "\n");
if (commands == NULL)
{
	fprintf(stderr, "Error: malloc failed\n");
	free(filter);
	exit(EXIT_FAILURE);
}
free(filter);

printf("%s\n", commands[0]);
if (interpret(commands) == 1)
	exit(EXIT_FAILURE);

return (0);
}
