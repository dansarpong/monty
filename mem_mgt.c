#include "monty.h"

/**
  * free_stack - frees a stack_t stack
*/
void free_stack(void)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}
