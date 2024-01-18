#include "monty.h"

/**
 * monty_pint - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		set_op_tok_error(EXIT_FAILURE);
		return;
	}
		printf("%d\n", (*stack)->n);
	}
