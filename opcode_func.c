#include "monty.h"

/**
 * push - The opcode push pushes an element to the stack.
 * @stack: Pointer to the structure.
 * @line: Line of the opcode.
 * Return: No return.
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *node;

	(void) line;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = arg;
	if (*stack == NULL)
		node->next = NULL;
	else
		node->next = *stack;
	node->prev = NULL;
	*stack = node;
	if (node->next != NULL)
		node->next->prev = node;
}

/**
 * pall - The opcode pall prints all the values on the stack,
 *  starting from the top of the stack.
 * @stack: pointer to the structure.
 * @line: Line of the opcode.
 * Return: No return.
 */
void pall(stack_t **stack, unsigned int line)
{
	const stack_t *point;

	(void)line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	point = *stack;
	while (point != NULL)
	{
		printf("%d\n", point->n);
		point = point->next;
	}
}

/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: pointer to the structure.
 * @line: Line of the opcode.
 * Return: No return.
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *point;

	if (*stack == NULL)
		error(line, 3);
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		point = (*stack)->next;
		(*stack) = point;
		point = point->prev;
		(*stack)->prev = NULL;
		free(point);
	}
}

/**
 * pint - The opcode pint prints the value at the top of the stack.
 * @stack: pointer to the structure.
 * @line: Line of the opcode.
 * Return: No return.
 */
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
		error(line, 2);
	printf("%d\n", (*stack)->n);
}

/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: pointer to the structure.
 * @line: Line of the opcode.
 * Return: No return.
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *point;

	if (*stack == NULL || (*stack)->next == NULL)
		error(line, 4);
	point = (*stack)->next;
	(*stack)->prev = point;
	(*stack)->next = point->next;
	point->prev = NULL;
	point->next = *stack;
	*stack = point;
}
