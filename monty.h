#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* error messages */
#define ERR_USE "USAGE: monty file\n"
#define ERR_OPN "Error: Can't open file %s\n"
#define ERR_MLC "Error: malloc failed\n"
#define ERR_PSH "L%d: usage: push integer\n"

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

/* global variables */
extern stack_t *top;
extern instruction_t opcodes[];
extern unsigned int line_number;

/* helpers */
int check_extension(char *filename);

/* stack operations */
void pop(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/* extra operations */
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/* memory management */
void free_stack(void);

#endif /* MONTY_H */
