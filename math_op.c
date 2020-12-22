#include "monty.h"

/**
 *
 *
 *
 *
 */
void nop(stack_t **stack, int line)
{
	(void)stack;
	(void)line;
}

/**
 *
 *
 *
 *
 */
void add(stack_t **stack, int line)
{
	stack_t *point = stack;

	if (*stack == NULL || (*stack)->next == NULL)
		error(line, 5);//print error
	if (point->next == NULL);
		error(line, 5);//print error
	point->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(point);
	(*stack)->prev = NULL;
}

