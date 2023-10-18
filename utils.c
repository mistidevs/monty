#include "monty.h"

/**
* free_stack - frees a stack
* @stack: pointer to top
* @len: length of the stack to free
*
* Return: void
*/

void free_stack(stack_t *stack, unsigned int len)
{
stack_t *curr, *next;
unsigned int i = 0;

curr = stack;

while (i < len)
{
	next = curr->next;
	free(curr);
	curr = next;
	i++;
}
}

/**
* push_check - checks if the syntax of push is met
* @var: value to check if compatible
*
* Return: 0 if successful 1 if it fails
*/

int push_check(char *var)
{
int i;

if (var == NULL)
	return (1);
for (i = 0; var[i] != '\0'; i++)
{
	if (!isdigit(var[i]))
		return (1);
}

return (0);
}

/**
* op_check - checking if an opcode is valid
* @opcode: opcode to check
*
* Return: 0 if successful; 1 if it fails
*/

int op_check(char *opcode)
{
int i;

char *op_codes[3] = {"push", "pall", NULL};

for (i = 0; op_codes[i] != NULL; i++)
{
	if (strcmp(opcode, op_codes[i]) == 0)
		return (0);
}

return (1);
}

/**
* free_op_list - frees a list with pointers to pointers
* @op_list: pointer to pointers
*
* Return: void
*/

void free_op_list(char **op_list)
{
int i;

for (i = 0; op_list[i] != NULL; i++)
{
	free(op_list[i]);
}

free(op_list);
}
