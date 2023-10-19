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
* add - adding the top two elements of a stack
* then removing the top eleement
* @stack: pointer to the top element
* @line_number: the line_number we are on
*
* Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !((*stack)->next))
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

temp = (*stack)->next;
temp->n += (*stack)->n;
pop(stack, line_number);
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

/**
* sub - subtracting the top two elements of a stack
* then removing the top eleement
* @stack: pointer to the top element
* @line_number: the line_number we are on
*
* Return: void
*/

void sub(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !((*stack)->next))
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

temp = (*stack)->next;
temp->n -= (*stack)->n;
pop(stack, line_number);
}

/**
* divide - dividing the top two elements of a stack
* then removing the top eleement
* @stack: pointer to the top element
* @line_number: the line_number we are on
*
* Return: void
*/

void divide(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (!stack || !(*stack) || !((*stack)->next))
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

temp = (*stack)->next;
if ((*stack)->n == 0)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
}

temp->n /= (*stack)->n;
pop(stack, line_number);
}
