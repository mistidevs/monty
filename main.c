#include "monty.h"

unsigned int stack_len = 0;
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
stack_t *stack;

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

stack = NULL;
for (i = 0; commands[i] != NULL; i++)
{
	command = unpad(commands[i]);
	ops = strtow(command, " ");
	if (ops == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_op_list(commands), free_stack(stack), free(command);
		exit(EXIT_FAILURE);
	}
	if (op_check(ops[0]) == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", (i + 1), ops[0]);
		free_op_list(commands), free_op_list(ops), free_stack(stack), free(command);
		exit(EXIT_FAILURE);
	}
	if (strcmp(ops[0], "push") == 0)
	{
		if (push_check(ops[1]) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", i + 1);
			free_op_list(commands), free_op_list(ops);
			free(command), free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	if (ops[1] != NULL)
		op_select(ops[0])(&stack, atoi(ops[1]));
	else
		op_select(ops[0])(&stack, 0);
	free_op_list(ops), free(command);
}

free_stack(stack), free_op_list(commands);
return (0);
}
