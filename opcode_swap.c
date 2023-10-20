/* Description for opcode_swap.c */
#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_swap - It swaps the top two elmt of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 * @file: Pointer to the Monty bytecode file.
 */
void handle_swap(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		fclose(file); /* Ensure "file" is accessible in this scope */
		exit(EXIT_FAILURE);
	}
	int temp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
