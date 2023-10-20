#include "monty.h"
#include "opcode_functions.h"

/**
 * handle_nop - Handles the nop opcode, which does nothing.
 * @stack: Pointer to the head of the stack.
 * @line_number: Current line number in the bytecode file.
 */
void handle_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* The nop opcode does nothing, so there's no code to execute here. */
}
