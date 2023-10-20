#include "monty.h"

/**
 * execute_opcode - Executes Monty opcodes based on the provided input
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
 * @opcode: The Monty opcode to execute
 * @line: The entire line containing the instruction
 * @file: Pointer to the Monty bytecode file
 */

void execute_opcode(stack_t **stack, unsigned int line_number, char *opcode,
					char *line, FILE *file)
{
	if (strcmp(opcode, "push") == 0)
	{
		char *arg = strtok(NULL, " \t\n");

		if (arg == NULL || !is_number(arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(stack);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
