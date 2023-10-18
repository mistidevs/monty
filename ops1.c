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
	{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {NULL, NULL}
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
 * @line_number: number to add as content of node
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
else
{
	temp = *stack;
	*stack = new_node;
	new_node->next = temp;
	temp->prev = new_node;
}
}

/**
* pall - printing a stack
* @stack: pointer to top
* @line_number: unused
*
* Return: void
*/

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
stack_t *curr;
unsigned int i;

if (*stack == NULL)
	exit(EXIT_FAILURE);

curr = *stack;
for (i = 0; curr != NULL; i++)
{
	printf("%d\n", curr->n);
	curr = curr->next;
}
}

/**
* pint - printing the top element of a stack
* @stack: pointer to top
* @line_number: used
*
* Return: void
*/

void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}

/**
* pop - deleting the top element of a stack
* @stack: pointer to top
* @line_number: used
*
* Return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *curr, *prev, *next;

if (*stack == NULL)
{
	fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

curr = *stack;
prev = NULL;
if (prev == NULL)
	*stack = curr->next;

next = curr->next;
if (prev != NULL)
	prev->next = next;
if (next != NULL)
	next->prev = prev;

free(curr);
}
