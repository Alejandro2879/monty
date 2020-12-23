#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: Pointer to the structure.
 * @line: Respective line of the opcode.
 * Return: No return.
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * add - The opcode add adds the top two elements of the stack.
 * @stack: Pointer to the structure.
 * @line: Respective line of the opcode.
 * Return: No return.
 */
void add(stack_t **stack, unsigned int line)
{
	stack_t *point = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		error(line, 5);
	if (point->next == NULL)
		error(line, 5);
	point->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(point);
	(*stack)->prev = NULL;
}

