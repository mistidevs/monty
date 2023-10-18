#include "monty.h"

stack_t *stack;
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
char **commands, **ops;
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
	fprintf(stderr, "Error: malloc failed");
	free(raw);
	exit(EXIT_FAILURE);
}
free(raw);

stack = NULL;
for (i = 0; commands[i] != NULL; i++)
{
	command = unpad(commands[i]);
	free(commands[i]);
	ops = strtow(command, " ");
	if (ops == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(command);
		exit(EXIT_FAILURE);
	}
	push(&stack, atoi(ops[1]));
	free(ops[0]), free(ops[1]), free(ops);
	free(command);
}

printf("%d\n", i);
free_stack(stack, i);
free(commands);
return (0);
}
