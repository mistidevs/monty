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
char *raw, *command;
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
	fprintf(stderr, "Command splitting failed");
	free(raw);
	exit(EXIT_FAILURE);
}
free(raw);

for (i = 0; commands[i] != NULL; i++)
{
	command = unpad(commands[i]);
	free(commands[i]);
	printf("%s\n", command);
	free(command);
}

free(commands);
return (0);
}
