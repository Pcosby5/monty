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

		handle_push(stack, line_number, arg);
	}

	else if (strcmp(opcode, "pall") == 0)
	{
		handle_pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		handle_pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		handle_pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		handle_swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		handle_add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		handle_nop(stack, line_number);
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
