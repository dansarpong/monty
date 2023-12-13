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

/**
  * pre_quit - safely exit program in any state
 */
void pre_quit(void)
{
	free_stack();
	fclose(file);
	if (line)
		free(line);
}
