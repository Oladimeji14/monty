#include "monty.h"

void my_push(my_stack_t **my_stack, unsigned int line_number);
void my_print_all(my_stack_t **my_stack, unsigned int line_number);
void my_print_top(my_stack_t **my_stack, unsigned int line_number);
void my_pop(my_stack_t **my_stack, unsigned int line_number);
void my_swap(my_stack_t **my_stack, unsigned int line_number);

void my_push(my_stack_t **my_stack, unsigned int line_number)
{
    my_stack_t *temp, *new_node;
    int i;

    new_node = malloc(sizeof(my_stack_t));
    if (!new_node || !op_toks[1])
    {
        set_my_op_tok_error(!new_node ? my_malloc_error() : my_no_int_error(line_number));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if ((op_toks[1][i] == '-' && i == 0) || (op_toks[1][i] < '0' || op_toks[1][i] > '9'))
        {
            set_my_op_tok_error(my_no_int_error(line_number));
            return;
        }
    }
    new_node->num = atoi(op_toks[1]);

    temp = (*my_stack)->next;
    new_node->prev = *my_stack;
    new_node->next = temp;
    if (temp)
        temp->prev = new_node;
    (*my_stack)->next = new_node;
}

void my_print_all(my_stack_t **my_stack, unsigned int line_number)
{
    my_stack_t *temp = (*my_stack)->next;

    while (temp)
    {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
    (void)line_number;
}

void my_print_top(my_stack_t **my_stack, unsigned int line_number)
{
    if ((*my_stack)->next)
        printf("%d\n", (*my_stack)->next->num);
    else
        set_my_op_tok_error(my_pint_error(line_number));
}

void my_pop(my_stack_t **my_stack, unsigned int line_number)
{
    my_stack_t *next_node = (*my_stack)->next->next;

    if ((*my_stack)->next)
    {
        free((*my_stack)->next);
        if (next_node)
            next_node->prev = *my_stack;
        (*my_stack)->next = next_node;
    }
    else
        set_my_op_tok_error(my_pop_error(line_number));
}

void my_swap(my_stack_t **my_stack, unsigned int line_number)
{
    my_stack_t *temp;

    if ((*my_stack)->next && (*my_stack)->next->next)
    {
        temp = (*my_stack)->next->next;
        (*my_stack)->next->next = temp->next;
        (*my_stack)->next->prev = temp;
        if (temp->next)
            temp->next->prev = (*my_stack)->next;
        temp->next = (*my_stack)->next;
        temp->prev = *my_stack;
        (*my_stack)->next = temp;
    }
    else
        set_my_op_tok_error(my_short_stack_error(line_number, "swap"));
}
