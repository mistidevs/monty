#include "monty.h"

/**
* main - monty interpreter
* @ac: argument counter
* @av: argument vector
*
* Return: suitable integer
*/

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
char *unpads;
char __attribute__((unused)) *str1 = "push 6";
char __attribute__((unused)) *str2 = "   push 6";
char __attribute__((unused)) *str3 = "   push 6   ";
char __attribute__((unused)) *str4 = "    push    6    ";

unpads = unpad(str4);
if (unpads == NULL)
	printf("Error: unpadding failed");
else
	printf("%s\n", unpads);

return (0);
}
