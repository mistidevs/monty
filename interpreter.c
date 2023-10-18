#include "monty.h"

/**
* interpret - interpreting a monty line
* @commands: list of commands
*
* Return: 1 if error or 0 if success
*/

int interpret(char **commands)
{
stack_t *stack = NULL;
char *command, **ops;
int i;
for (i = 0; commands[i] != NULL; i++)
{
	if (check_new_line(commands[i]) == 0)
	{
		free_op_list(commands), free_stack(stack);
		return (1); }
	command = unpad(commands[i]);
	if (*command == '\0')
	{
		free(command), free_op_list(commands), free_stack(stack);
		return (1); }
	ops = strtow(command, " ");
	if (ops == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n"), free_op_list(commands);
		free_stack(stack), free(command);
		return (1); }
	if (op_check(ops[0]) == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", (i + 1), ops[0]);
		free_op_list(commands), free_op_list(ops), free_stack(stack), free(command);
		return (1); }
	if (strcmp(ops[0], "push") == 0)
	{
		if (push_check(ops[1]) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", i + 1);
			free_op_list(commands), free_op_list(ops), free(command), free_stack(stack);
			return (1); }
	}
	if (ops[1] != NULL)
		op_select(ops[0])(&stack, atoi(ops[1]));
	else
		op_select(ops[0])(&stack, (i + 1));
	free_op_list(ops), free(command); }
free_stack(stack), free_op_list(commands);
return (0);
}
