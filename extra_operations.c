#include "monty.h"

/**
  * pall - prints all the elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 on success
*/
void pall(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp = top;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
  * pint - prints the top element of the stack
  * @s: unused
  * @l: unused
  * Return: 0 on success
*/
void pint(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	if (!top)
	{
		fprintf(stderr, ERR_PNT, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}

/**
  * nop - does nothing
  * @s: unused
  * @l: unused
  * Return: 0 on success
*/
void nop(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l) {}
