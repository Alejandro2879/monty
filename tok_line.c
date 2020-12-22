#include "monty.h"

/**
 *
 *
 *
 *
 */
char **tok_line(char *line)
{
	char **box_tok, *token;
	int iter = 0;

	box_tok = malloc(sizeof(char *) *3);
	if (!box_tok)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " '\n'");
	if (!token)
	{
		free(box_tok);
		return (NULL);
	}
	while (token != NULL && iter < 2)
	{
		box_tok[iter] = token;
		token = strtok(line, " '\n'");
		iter++;
	}
	box_tok[iter] = NULL;
	return(box_tok);
}
