#include "monty.h"

stack_t *top = NULL;
char *value, *line;
int line_number = 0, stack_mode = 1;
FILE *file;
instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", dvd},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

void read_run(void);

/**
  * main - entry point
  * @argc: argument count
  * @argv: argument vector
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, ERR_USE);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, ERR_OPN, argv[1]);
		exit(EXIT_FAILURE);
	}

	read_run();
	return (0);
}

/**
  * read_run - read and run opcodes from file
*/
void read_run(void)
{
	size_t len = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (line[0] == '\n')
			continue;
		run_opc(&line);
	}

	pre_quit();
}
