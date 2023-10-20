/* Description for opcode_pint.c */
#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_pint -It prints the value at the top of stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 * @file: Pointer to the Monty bytecode file.
 */
void handle_pint(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		fclose(file); /* Ensure "file" is accessible in this scope */
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
