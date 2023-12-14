#include "monty.h"

/**
  * push - pushes an element onto the structure
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void push(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *new = malloc(sizeof(stack_t));
	int i = atoi(value);
	char buf[10];

	if (new == NULL)
	{
		fprintf(stderr, ERR_MLC);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	sprintf(buf, "%d", i);
	if (value == NULL || (strcmp(value, buf) != 0))
	{
		fprintf(stderr, ERR_PSH, line_number);
		free(new);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	new->n = i;
	if (stack_mode == 1)
		addnode(new);
	else
		addnode_end(new);
}

/**
  * pop - removes the top element
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void pop(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL)
	{
		fprintf(stderr, ERR_POP, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top;
	top = top->next;
	free(tmp);
}

/**
  * swap - swaps the top two elements of the stack
  * @s: unused
  * @l: unused
*/
void swap(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	int tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_SWP, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
}

/**
  * rotl - rotates the stack to the top
  * @s: unused
  * @l: unused
 */
void rotl(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp = top, *last = top;

	if (!top || !top->next)
		return;

	while (last->next)
		last = last->next;

	top = top->next;
	top->prev = NULL;
	tmp->next = NULL;

	last->next = tmp;
	tmp->prev = last;
}

/**
  * rotr - rotates the stack to the top
  * @s: unused
  * @l: unused
 */
void rotr(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *last = top;

	if (!top || !top->next)
		return;

	while (last->next)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;

	last->next = top;
	top->prev = last;
	top = last;
}
