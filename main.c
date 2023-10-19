#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"

/**
* main - monty interpreter
* @ac: argument counter
* @av: argument vector
*
* Return: suitable integer
*/

int main(int ac, char **av)
{
FILE *fp;

if (ac != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

fp = fopen(av[1], "r");
if (fp == NULL)
{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
}

if (interpret(fp) == 1)
	exit(EXIT_FAILURE);


fclose(fp);

return (0);
}
