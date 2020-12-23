#include "monty.h"
/**
 * error - Print error.
 * @line: Line where the error is.
 * @op: Number of the error to print.
 * Return: Noo return.
 */
void error(unsigned int line, int op)
{
	if (op == 1)
		dprintf(STDERR_FILENO, "L%d: usage: push integer", line);
	else if (op == 2)
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line);
	else if (op == 3)
		dprintf(STDERR_FILENO,"L%d: can't pop an empty stack\n", line);
	else if (op == 4)
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line);
	else if (op == 5)
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line);
	else if (op == 6)
	exit(EXIT_FAILURE);
}

