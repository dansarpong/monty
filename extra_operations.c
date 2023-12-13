#include "monty.h"

/**
  * pall - prints all the elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 on success
*/
int pall(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp = top;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return (0);
}

/**
  * pint - prints the top element of the stack
  * @s: unused
  * @l: unused
  * Return: 0 on success
*/
int pint(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	if (!top)
	{
		fprintf(stderr, ERR_PNT, line_number);
		return (1);
	}

	printf("%d\n", top->n);
	return (0);
}

/**
  * nop - does nothing
  * @s: unused
  * @l: unused
  * Return: 0 on success
*/
int nop(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	return (0);
}
