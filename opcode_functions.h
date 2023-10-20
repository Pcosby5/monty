#ifndef OPCODE_FUNCTIONS_H
#define OPCODE_FUNCTIONS_H

#include "monty.h"

void handle_push(stack_t **stack, unsigned int line_number, char *arg);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_add(stack_t **stack, unsigned int line_number);
void handle_nop(stack_t **stack, unsigned int line_number);

#endif /* OPCODE_FUNCTIONS_H */
