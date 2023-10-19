#include "monty.h"

modes_t mode = STACK;

/**
* rotl - rotating a stack making the top the bottom
* @stack: pointer to top
* @line_number: unused
*
* Return: void
*/

void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
(void)line_number;

if (stack && *stack && (*stack)->next)
{
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
}

/**
* rotr - rotating a stack making the bottom the top
* @stack: pointer to top
* @line_number: unused
*
* Return: void
*/

void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
(void)line_number;

if (!stack || !*stack || !(*stack)->next)
{
	return;
}

temp = *stack;
while (temp->next != NULL)
{
	temp = temp->next;
}

temp->prev->next = NULL;
temp->prev = NULL;
temp->next = *stack;
(*stack)->prev = temp;
*stack = temp;
}

/**
* stack - setting the mode to STACK
* @stack: pointer to top
* @line_number: unused
*
* Return: void
*/

void stack_change(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    mode = STACK;
}

/**
* queue - setting the mode to QUEUE
* @stack: pointer to top
* @line_number: unused
*
* Return: void
*/

void queue_change(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    mode = QUEUE;
}
