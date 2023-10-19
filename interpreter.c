#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
* interpret - interpreting a monty line
* @fp: file pointer
*
* Return: 1 if error or 0 if success
*/

int interpret(FILE *fp)
{
char *command, **ops, *line;
size_t len = 0;
int i = 0;
stack_t *stack = NULL;
while (getline(&line, &len, fp) != -1)
{
	if (line[0] == '\0' || line[0] == '\n')
	{
		i++;
		continue; }
	command = unpad(line);
	if (command[0] == '\0' || command[0] == '\n')
	{
		i++;
		continue; }
	ops = strtow(command, " ");
	if (ops == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(command), free(line), free_stack(stack);
		return (1); }
	if (op_check(ops[0]) == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", (i + 1), ops[0]);
		free_op_list(ops), free(command), free(line), free_stack(stack);
		return (1); }
	if (strcmp(ops[0], "push") == 0)
	{
		if (push_check(ops[1]) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", i + 1);
			free_op_list(ops), free(command), free(line), free_stack(stack);
			return (1); }
	}
	if (strcmp(ops[0], "push") == 0)
		op_select(ops[0])(&stack, atoi(ops[1]));
	else if (strcmp(ops[0], "push") != 0)
		op_select(ops[0])(&stack, (i + 1));
	free(line), line = NULL, len = 0, i++;
	free_op_list(ops), free(command);
}
free_stack(stack), free(line);
return (0);
}
