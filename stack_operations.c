#include "monty.h"

/**
  * pop - removes the top element of the stack
*/
void pop(void)
{
	stack_t *tmp;

	if (top == NULL)
	{
		/* TODO: errmsg */
		exit();
	}

	tmp = top;
	top = top->next;
	free(tmp);
}

/**
  * push - pushes an element to the stack
  * @n: element to be added to the stack
*/
void push(int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		/* TODO: errmsg */
		exit();
	}

	new->n = n;
	new->next = top;
	new->prev = NULL;
	if (top != NULL)
		top->prev = new;
	top = new;
}

/**
  * add - add the top two elements of the stack
*/
void add(void)
{
	stack_t *tmp;
	int n;

	if (top == NULL || top->next == NULL)
	{
		/* TODO: errmsg */
		exit();
	}

	tmp = top;
	top = top->next;
	n = tmp->n + top->n;
	top->n = n;
	top->prev = NULL;
	free(tmp);
}

/**
  * swap - swaps the top two elements of the stack
*/
void swap(void)
{
	int tmp;

	if (top == NULL || top->next == NULL)
	{
		/* TODO: errmsg */
		exit();
	}

	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
}
