#include "monty.h"

modes_t mode = STACK;

/**
 * push_neg - adds node to a stack where line_number is negative
 * @stack: the pointer to the pointer to the top of the stack
 * @line_number: number to add as content of node
 *
 * Return: pointer to first node
 */

void push_neg(stack_t **stack, int line_number)
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

if (*stack == NULL || stack == NULL)
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

if (mode == QUEUE)
	rotl(stack, line_number);
}

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

if (stack && *stack && (*stack)->next)
{
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
}

/**
* stack_change - setting the mode to STACK
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
* queue_change - setting the mode to QUEUE
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
