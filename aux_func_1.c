#include "monty.h"
#include <stdlib.h> //NULL - EXIT
int arg = 0; /* global (extern) variable defined in header */

/**
 * get_func - Call the respective opcode function.
 * @tok_text:
 * @line:
 *
 */
void (*get_func(char **tok_text, int line))(stack_t **, int li)
{
        int iter = 0;

        instruction_t ops[] = {
                {"push", push},
                {"pall", pall},
                {"pop", pop},
                {"pint", pint},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {NULL, NULL}
        };

        while (ops[iter].opcode != NULL)
        {
                if (strcmp(ops[iter].opcode, tok_text[0]) == 0)
                {
                        if ((strcmp(ops[iter].opcode, "push") == 0) &&
                                (tok_text[1] == NULL || (!(valid(tok_text[1])))))
                        {
                                free(tok_text);
                                printf("L%d: usage: push integer", line);
                                exit(EXIT_FAILURE);
                        }
                        else if (strcmp(ops[iter].opcode, "push") == 0)
                                arg = atoi(tok_text[1]);
                        free(tok_text);
                        return(ops[iter].f);
                }
                iter++;
        }
        printf("L%d: unknown instruction %s\n", line, tok_text[0]);
        free(tok_text);
        exit(EXIT_FAILURE);
}
