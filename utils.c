#include "monty.h"

/**
* free_stack - frees a stack
* @stack: pointer to top
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
