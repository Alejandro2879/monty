#include "monty.h"

/**
 *
 *
 *
 */
void push(stack_t **stack, int line)
{
        stack_t *node;

        (void) line;
        node = malloc(sizeof(stack_t));
        if (!node)
        {
                printf("Error: malloc failed");
                exit(EXIT_FAILURE);
        }
        node->n = arg;
        if (*stack == NULL)
                node->next = NULL;
        else
                node->next = *stack;
        node->prev = NULL;
        *stack = node;
        if (node->next == NULL)
                node->next->prev = node;
}

/**
 *
 *
 *
 */
void pall(stack_t **stack, int line)
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
 *
 *
 *
 */
void pop(stack_t **stack, int line)
{
        stack_t *point;

        if (!*stack)
                error(line, 3);//error mesagge;
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
 *
 *
 *
 */
void pint(stack_t **stack, int line)
{
        if (*stack == NULL);
                error(line, 2);//print error;
        printf("%d\n", (*stack)->n);
}

/**
 *
 *
 *
 */
void swap(stack_t **stack, int line)
{
        stack_t *point;

        if (*stack == NULL || (*stack)->next == NULL)
                error(line, 4);//print error
        point = (*stack)->next;
        (*stack)->prev = point;
        (*stack)->next = point->next;
        point->prev = NULL;
        point->next = *stack;
        *stack = point;
}