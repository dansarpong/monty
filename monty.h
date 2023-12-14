#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/* error messages */
#define ERR_USE "USAGE: monty file\n"
#define ERR_OPN "Error: Can't open file %s\n"
#define ERR_UKN "L%d: unknown instruction %s\n"
#define ERR_MLC "Error: malloc failed\n"
#define ERR_PSH "L%d: usage: push integer\n"
#define ERR_PNT "L%d: can't pint, stack empty\n"
#define ERR_POP "L%d: can't pop an empty stack\n"
#define ERR_SWP "L%d: can't swap, stack too short\n"
#define ERR_ADD "L%d: can't add, stack too short\n"
#define ERR_SUB "L%d: can't sub, stack too short\n"
#define ERR_DIV "L%d: can't div, stack too short\n"
#define ERR_DBZ "L%d: division by zero\n"
#define ERR_MUL "L%d: can't mul, stack too short\n"
#define ERR_MOD "L%d: can't mod, stack too short\n"
#define ERR_PCR "L%d: can't pchar, value out of range\n"
#define ERR_PCS "L%d: can't pchar, stack empty\n"

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
extern char *value, *line;
extern stack_t *top;
extern int line_number;
extern FILE *file;
extern instruction_t opcodes[];

/* helpers */
int check_extension(char *);
void run_opc(char **);
int printchar(int);

/* stack operations */
void push(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/* stack operations 2 */
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void dvd(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/* extra operations */
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

/* memory management */
void free_stack(void);
void pre_quit(void);

#endif /* MONTY_H */
