#include "monty.h"

/**
 * free_stack - Frees all nodes in the stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *temp;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}

	*stack = NULL;
}
