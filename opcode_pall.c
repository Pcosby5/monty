/* Description for opcode_pall.c */
#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_pall - Handles the pall opcode,it prints all elmts on stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
