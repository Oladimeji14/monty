#include "monty.h"

/**
 * my_swap - Swaps the top two elements of the stack.
 * @my_stack: Pointer to the top of the stack.
 * @line_number: Line number of the current operation.
 */
void my_swap(my_stack_t **my_stack, unsigned int line_number)
{
    int temp;

    if (*my_stack == NULL || (*my_stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        set_my_op_tok_error(EXIT_FAILURE);
        return;
    }

    temp = (*my_stack)->next->num;
    (*my_stack)->next->num = (*my_stack)->num;
    (*my_stack)->num = temp;
}
