/* Description for opcode_pop.c */
#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_pop - Handles the pop opcode, it removes the top elmt from stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 * @file: Pointer to the Monty bytecode file.
 */
void handle_pop(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		fclose(file); /* Ensure "file" is accessible in this scope */
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
