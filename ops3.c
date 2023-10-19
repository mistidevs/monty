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

/**
* comment - handling comments
* @stack: unused
* @line_number: unused
*
* Return: void
*/

void comment(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
return;
}

/**
* pchar - printing the ascii value of a digit
* @stack: pointer to top
* @line_number: line number we are on
*
* Return: void
*/

void pchar(stack_t **stack, unsigned int line_number)
{
int ascii_val;

if (stack == NULL || *stack == NULL)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

ascii_val = (*stack)->n;

if (ascii_val < 0 || ascii_val > 127)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
}

printf("%c\n", ascii_val);
}

/**
* pstr - printing the ascii values of digits in a stack
* @stack: pointer to top
* @line_number: line number we are on
*
* Return: void
*/

void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
(void)line_number;

if (!stack || !*stack)
{
	printf("\n");
}
else
{
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n > 0 && temp->n < 128)
		{
			printf("%c", temp->n);
		}
		else
		{
				break;
		}
		temp = temp->next;
	}
printf("\n");
}
}
