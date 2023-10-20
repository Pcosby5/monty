#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_push - Handles the push opcode,it pushes an elmt onto stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 * @arg: The argument provided to the push opcode (should be an integer).
 * @file: Pointer to the Monty bytecode file.
 */
void handle_push(stack_t **stack, unsigned int line_number,
		char *arg, FILE *file)
{
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		fclose(file); /* Ensure "file" is accessible in this scope */
		exit(EXIT_FAILURE);
	}
	push(stack, atoi(arg));
}
