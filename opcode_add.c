#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_add - Handles the add opcode, adds the top two elmt of stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 * @file: Pointer to the Monty bytecode file
 */
void handle_add(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		fclose(file); /* Ensure "file" is accessible in this scope */
		exit(EXIT_FAILURE);
	}

	int result = (*stack)->n + (*stack)->next->n;

	handle_pop(stack, line_number, result); /* Remove the top element */
}
