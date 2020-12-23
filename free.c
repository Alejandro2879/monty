#include "monty.h"

/**
 * own_free - Free allocated memory.
 * @stack: pointer to the allocated memory.
 * Return: no return.
 */
void own_free(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp == NULL)
			return;
		temp->prev = NULL;
		*stack = temp;
	}
	free(*stack);
}
