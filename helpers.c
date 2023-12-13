#include "monty.h"

/**
  * check_extension - check for the extension of the file (.m)
  * @file: file to check
  * Return: 0 on success
*/
int check_extension(char *file)
{
	int i = 0;

	while (file[i])
		i++;
	if (file[i - 1] != 'm' || file[i - 2] != '.')
		return (1);
	return (0);
}

/**
  * run_opc - run opcode
  * @line: line to read
*/
void run_opc(char **line)
{
	char *opcode, *value;
	int i;

	opcode = strtok(*line, " \n\t");
	if (opcode == NULL)
		return;
	value = strtok(NULL, " \n\t");
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(value);
			return;
		}
	}
}
