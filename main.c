#include "monty.h"

stack_t *top = NULL;
char *value, *line;
int line_number = 0;
FILE *file;
instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
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
	char *f;

	if (argc != 2)
	{
		fprintf(stderr, ERR_USE);
		exit(EXIT_FAILURE);
	}

	f = argv[1];
	if (check_extension(f) == 1)
	{
		fprintf(stderr, ERR_OPN, f);
		exit(EXIT_FAILURE);
	}

	file = fopen(f, "r");
	if (!file)
	{
		fprintf(stderr, ERR_OPN, f);
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
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (line[0] == '\n')
			continue;
		run_opc(&line);
	}

	pre_quit();
}
