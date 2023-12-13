#include "monty.h"

/**
  * main - entry point
  * @argc: argument count
  * @argv: argument vector
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char **argv)
{
	char *f;
	stack_t *top = NULL;
	FILE *file;

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
	if (file == -1)
	{
		fprintf(stderr, ERR_OPN, f);
		exit(EXIT_FAILURE);
	}

	read_run(file);
	fclose(file);
	free_stack();
	return (0);
}

/**
  * read_run - read and run opcodes from file
  * @file: file to read
  * Return: 0 upon success, 1 otherwise (exit)
*/
int read_run(FILE *file)
{
	char *line = NULL, *tmp;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[0] == '\n')
			continue;
		tmp = line;
		run_opc(&tmp);
	}

	free(line);
	return (0);
}
