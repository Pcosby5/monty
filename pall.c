#include "monty.h"

/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number; /* Unused parameter */

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
