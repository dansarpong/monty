#include "monty.h"

/**
  * print_all - prints all the elements of the stack
*/
void print_all(void)
{
	stack_t *tmp = top;

	while (tmp != NULL)
	{
		/* TODO: print */
		tmp = tmp->next;
	}
}

/**
  * print_top - prints the top element of the stack
*/
void print_top(void)
{
	if (!top)
	{
		/* TODO: errmsg */
		exit();
	}

	/* TODO: print */
}

/**
  * nop - does nothing
*/
void nop(void) {}
