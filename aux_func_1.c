#include "monty.h"
int arg = 0;
/**
 * get_func - Call the respective opcode function.
 * @tok_text: Each line in opcode.
 * @line: Respecctive line of the opcode.
 * Return: No return.
 */

void (*get_func(char **tok_text, unsigned int line))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int iter = 0;

	if (tok_text[0][0] == '#')
	{
		free(tok_text);
		return (nop);
	}

	while (ops[iter].opcode != NULL)
	{
		if ((strcmp(ops[iter].opcode, tok_text[0]) == 0))
		{
			if ((strcmp(ops[iter].opcode, "push") == 0) &&
				(tok_text[1] == NULL || (!(valid(tok_text[1])))))
			{
				free(tok_text);
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			else if ((strcmp(ops[iter].opcode, "push") == 0))
				arg = atoi(tok_text[1]);
			free(tok_text);
			return (ops[iter].f);
		}
		iter++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, tok_text[0]);
	free(tok_text);
	exit(EXIT_FAILURE);
}
