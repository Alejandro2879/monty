#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: Counter of command line arguments.
 * @argv: Argmuments of the user.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *file;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	open_file(file);
	return (0);
}

/**
 * open_file - Open file with opcode.
 * @file: File to open.
 * Return: No return.
 */
void open_file(char *file)
{
	FILE *open_f;
	char *buffer = NULL, **tok_text;
	int line = 0;
	size_t size = 0;
	stack_t *stack = NULL;

	open_f = fopen(file, "r");
	if (!open_f)
	{
		printf("Error: Can't open file %s", file);
		exit(EXIT_FAILURE);
	}

	while (-1 != getline(&buffer, &size, open_f))
	{
		line++;
		tok_text = tok_line(buffer);
		if (!tok_text)
			continue;
		else
			get_func(tok_text, line)(&stack, line);
	}

	fclose(open_f);
	free(buffer);
	own_free(&stack);
}
