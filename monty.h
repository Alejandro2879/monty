#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int arg;

void open_file(char *file);
void (*get_func(char **, unsigned int))(stack_t **, unsigned int);
char **tok_line(char *line);
int valid(char *token);
void own_free(stack_t **stack);
void error(unsigned int line, int op);

void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);



#endif /* MONTY_H */
