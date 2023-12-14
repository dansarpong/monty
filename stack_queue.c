#include "monty.h"

/**
  * stack - sets the format of the data to a stack (LIFO)
  * @s: unused
  * @l: unused
 */
void stack(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_mode = 1;
}

/**
  * queue - sets the format of the data to a queue (FIFO)
  * @s: unused
  * @l: unused
 */
void queue(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_mode = 0;
}

/**
  * addnode - adds a node to the end of the list
  * @new: node to add
 */
void addnode(stack_t *new)
{
	new->next = top;
	new->prev = NULL;
	if (top != NULL)
		top->prev = new;
	top = new;
}

/**
  * addnode_end - adds a node to the end of the list
  * @new: node to add
 */
void addnode_end(stack_t *new)
{
	stack_t *tmp = top;

	if (top == NULL)
	{
		top = new;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}
