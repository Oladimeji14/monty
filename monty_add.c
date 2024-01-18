#include "monty.h"

/**
 * monty_add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		set_op_tok_error(EXIT_FAILURE);
		return;
	}
		(*stack)->next->n += (*stack)->n;
		monty_pop(stack, line_number);
	}
