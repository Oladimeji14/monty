#include "monty.h"
#include <stdlib.h>

/* Declare op_toks without initialization */

/**
 * monty_push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the current operation
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	char *token;
	stack_t *new_node;

	token = op_toks[1];

	if (!token || atoi(token) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		set_op_tok_error(EXIT_FAILURE);
		return;
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		malloc_error();
		return;
	}

	new_node->n = atoi(token);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)

	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
/**
 *monty_pall - Prints all elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 */

void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
