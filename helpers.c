#include "monty.h"

/**
  * run_opc - run opcode
  * @line: line to read
*/
void run_opc(char **line)
{
	char *opcode, *tmp = *line;
	int i;

	opcode = strtok(tmp, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return;
	value = strtok(NULL, " \n\t");
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(NULL, 0);
			return;
		}
	}

	fprintf(stderr, ERR_UKN, line_number, opcode);
	pre_quit();
	exit(EXIT_FAILURE);
}

/**
 * printchar - prints a character by their ascii value
 * @n: ascii value to check and print
 * Return: 0 on success
 */
int printchar(int n)
{
	if (n < 0 || n > 127)
		return (1);

	printf("%c", (char)n);
	return (0);
}

/**
  * free_stack - frees a stack_t stack
*/
void free_stack(void)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}

/**
  * pre_quit - safely exit program in any state
 */
void pre_quit(void)
{
	free_stack();
	fclose(file);
	if (line)
		free(line);
}
