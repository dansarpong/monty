#include "monty.h"

/**
	* pchar - prints the char at the top of the stack
	* @s: unused
	* @l: unused
*/
void pchar(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	if (!top)
	{
		fprintf(stderr, ERR_PCS, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	if (printchar(top->n) != 0)
	{
		fprintf(stderr, ERR_PCR, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}
	printf("\n");
}

/**
  * pstr - prints the string starting at the top of the stack
  * @s: unused
  * @l: unused
*/
void pstr(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp = top;

	while (tmp)
	{
		if (tmp->n == 0 || printchar(tmp->n) != 0)
			break;

		tmp = tmp->next;
	}
	printf("\n");
}
