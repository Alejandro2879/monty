#include "monty.h"

/**
 *
 *
 *
 */
void free(stack_t **stack)
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
