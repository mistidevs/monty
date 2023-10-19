#include "monty.h"

/**
* swap - swaps the top two elements of a stack
* @stack: pointer to top
* @line_number: line we are on
*
* Return: void
*/

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !((*stack)->next))
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

temp = (*stack)->next;
(*stack)->prev = temp;
(*stack)->next = temp->next;
if (temp->next)
	temp->next->prev = *stack;
temp->next = *stack;
temp->prev = NULL;
*stack = temp;
}

/**
* nop - does nothing
* @stack: pointer to top
* @line_number: unused
*
* Return: void
*/

void nop(stack_t **stack,
	unsigned int line_number)
{
(void)stack;
(void)line_number;
return;
}
