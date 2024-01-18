#include "monty.h"
/**
 * monty_pop - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		set_op_tok_error(EXIT_FAILURE);
		return;
	}
		temp = *stack;
		*stack = temp->next;
		
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
			free(temp);
}
