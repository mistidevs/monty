#include "monty.h"

/**
* mul - multiplying the top two elements of a stack
* then removing the top element
* @stack: pointer to the top element
* @line_number: the line_number we are on
*
* Return: void
*/

void mul(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !((*stack)->next))
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

temp = (*stack)->next;
temp->n *= (*stack)->n;
pop(stack, line_number);
}

/**
* mod - modulo operating the top two elements of a stack
* then removing the top eleement
* @stack: pointer to the top element
* @line_number: the line_number we are on
*
* Return: void
*/

void mod(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !((*stack)->next))
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

temp = (*stack)->next;
if ((*stack)->n == 0)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}

temp->n %= (*stack)->n;
pop(stack, line_number);
}
