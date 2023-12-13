#include "monty.h"

/**
  * push - pushes an element to the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
int push(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *new = malloc(sizeof(stack_t));
	int i = atoi(value);

	if (new == NULL)
	{
		fprintf(stderr, ERR_MLC);
		return (1);
	}

	if (i == 0 && value[0] != '0')
	{
		fprintf(stderr, ERR_PSH, line_number);
		return (1);
	}

	new->n = i;
	new->next = top;
	new->prev = NULL;
	if (top != NULL)
		top->prev = new;
	top = new;
	return (0);
}

/**
  * pop - removes the top element of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
int pop(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL)
	{
		fprintf(stderr, ERR_POP, line_number);
		return (1);
	}

	tmp = top;
	top = top->next;
	free(tmp);
	return (0);
}

/**
  * swap - swaps the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
int swap(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	int tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_SWP, line_number);
		return (1);
	}

	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
	return (0);
}

/**
  * add - add the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
int add(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;
	int n;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_ADD, line_number);
		return (1);
	}

	tmp = top;
	top = top->next;
	n = tmp->n + top->n;
	top->n = n;
	top->prev = NULL;
	free(tmp);
	return (0);
}
