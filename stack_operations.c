#include "monty.h"

/**
  * push - pushes an element to the stack
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
	new->next = top;
	new->prev = NULL;
	if (top != NULL)
		top->prev = new;
	top = new;
}

/**
  * pop - removes the top element of the stack
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
  * Return: 0 upon success
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
