#define _GNU_SOURCE
#include "monty.h"

/**
 * main - Entry point for the Monty program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL; /* Initialize an empty stack */
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		/* Tokenize the line to extract the opcode and arguments */
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || *opcode == '#')
			continue; /* Ignore empty lines and comments */

		execute_opcode(&stack, line_number, opcode, line, file);
	}

	/* Free allocated memory and close the file */
	free_stack(&stack);
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
