#include "monty.h"

/**
  * add - add the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void add(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_ADD, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top;
	top = top->next;
	top->n += tmp->n;
	top->prev = NULL;
	free(tmp);
}

/**
  * sub - add the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void sub(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_SUB, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top;
	top = top->next;
	top->n -= tmp->n;
	top->prev = NULL;
	free(tmp);
}

/**
  * divide - divide the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void dvd(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_DIV, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, ERR_DBZ, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top;
	top = top->next;
	top->n /= tmp->n;
	top->prev = NULL;
	free(tmp);
}

/**
  * mul - multiply the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void mul(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_MUL, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top;
	top = top->next;
	top->n *= tmp->n;
	top->prev = NULL;
	free(tmp);
}

/**
  * mod - compute the modulus of the top two elements of the stack
  * @s: unused
  * @l: unused
  * Return: 0 upon success
*/
void mod(__attribute__((unused))stack_t **s,
		__attribute__((unused))unsigned int l)
{
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, ERR_MOD, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, ERR_DBZ, line_number);
		pre_quit();
		exit(EXIT_FAILURE);
	}

	tmp = top;
	top = top->next;
	top->n %= tmp->n;
	top->prev = NULL;
	free(tmp);
}
