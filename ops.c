#include "monty.h"

/**
* op_select - selecting the appropriate op
* @opcode: opcode to check
*
* Return: op function or NULL
*/

void (*op_select(char *opcode))(stack_t **, unsigned int)
{
int i;

instruction_t instructions[] = {
	{"push", push}, {NULL, NULL}
};

for (i = 0; instructions[i].opcode != NULL; i++)
{
	if (strcmp(opcode, instructions[i].opcode) == 0)
		return (instructions[i].f);
}

return (NULL);
}

/**
 * push - adds node to a stack
 * @stack: the pointer to the pointer to the top of the stack
 * @n: number to add as content of node
 *
 * Return: pointer to first node
 */

void push(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
stack_t *new_node;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
new_node->n = line_number;
new_node->prev = NULL;

if (*stack == NULL)
{
	*stack = new_node;
	new_node->next = NULL;
}

temp = *stack;
*stack = new_node;
new_node->next = temp;
temp->prev = new_node;
}
