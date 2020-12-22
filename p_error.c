#include "monty.h"

/**
 *
 *
 *
 *
 */
void error(int line, int op)
{
	if (op == 1)
		printf("L%d: usage: push integer", line);
	else if (op == 2)
		printf("L%d: can't pint, stack empty\n", line);
	else if (op == 3)
		printf("L%d: can't pop an empty stack\n", line);
	else if (op == 4)
		printf("L%d: can't swap, stack too short\n", line);
	else if (op == 5)
		printf("L%d: can't add, stack too short\n", line);
	else if (op == 6)
		printf("L%d: can't sub, stack too short\n", line);
	else if (op == 7)
		printf("L%d: can't div, stack too short\n", line);
	else if (op == 8)
		printf("L%d: division by zero\n", line);
	else if (op == 9)
		printf("L%d: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}

