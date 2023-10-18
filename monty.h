#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**** EXTERNS ***/
extern unsigned int line_number;
extern stack_t *stack;
extern unsigned int stack_len;

/**** PREPROCESSOR *****/
char *unpad(char *line);
char **strtow(char *str, const char *d);
int is_delim(char c, const char *delim);
int count_words(char *str, const char *delimiter);

/***** FILE PROCESSING ****/
char *open_file(char *filename);

/***** OPS **********/
void (*op_select(char *opcode))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/******* UTILITIES **********/
void free_stack(stack_t *stack);
int push_check(char *var);
int op_check(char *opcode);
void free_op_list(char **op_list);

#endif
