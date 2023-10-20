#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

		*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
