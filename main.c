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
char *raw;
char **commands;
int i;

if (ac != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

raw = open_file(av[1]);
if (raw == NULL)
	exit(EXIT_FAILURE);

commands = strtow(raw, "\n");
if (commands == NULL)
{
	fprintf(stderr, "Error: malloc failed\n");
	free(raw);
	exit(EXIT_FAILURE);
}
free(raw);

for (i = 0; commands[i] != NULL; i++)
{
	if (commands[i][0] == '\0')
		printf("Empty\n");
	printf("%s\n", commands[i]);
}
if (interpret(commands) == 1)
	exit(EXIT_FAILURE);

return (0);
}
