#include "monty.h"

void my_add_op(my_stack_t **my_stack, unsigned int line_number);
void my_sub_op(my_stack_t **my_stack, unsigned int line_number);
void my_div_op(my_stack_t **my_stack, unsigned int line_number);
void my_mul_op(my_stack_t **my_stack, unsigned int line_number);
void my_mod_op(my_stack_t **my_stack, unsigned int line_number);

void my_add_op(my_stack_t **my_stack, unsigned int line_number)
{
    if ((*my_stack)->next && (*my_stack)->next->next)
    {
        (*my_stack)->next->next->num += (*my_stack)->next->num;
        my_pop(my_stack, line_number);
    }
    else
        set_my_op_tok_error(my_short_stack_error(line_number, "add"));
}

void my_sub_op(my_stack_t **my_stack, unsigned int line_number)
{
    if ((*my_stack)->next && (*my_stack)->next->next)
    {
        (*my_stack)->next->next->num -= (*my_stack)->next->num;
        my_pop(my_stack, line_number);
    }
    else
        set_my_op_tok_error(my_short_stack_error(line_number, "sub"));
}

void my_div_op(my_stack_t **my_stack, unsigned int line_number)
{
    if ((*my_stack)->next && (*my_stack)->next->next)
    {
        if ((*my_stack)->next->num == 0)
        {
            set_my_op_tok_error(my_div_error(line_number));
            return;
        }
        (*my_stack)->next->next->num /= (*my_stack)->next->num;
        my_pop(my_stack, line_number);
    }
    else
        set_my_op_tok_error(my_short_stack_error(line_number, "div"));
}

void my_mul_op(my_stack_t **my_stack, unsigned int line_number)
{
    if ((*my_stack)->next && (*my_stack)->next->next)
    {
        (*my_stack)->next->next->num *= (*my_stack)->next->num;
        my_pop(my_stack, line_number);
    }
    else
        set_my_op_tok_error(my_short_stack_error(line_number, "mul"));
}

void my_mod_op(my_stack_t **my_stack, unsigned int line_number)
{
    if ((*my_stack)->next && (*my_stack)->next->next)
    {
        if ((*my_stack)->next->num == 0)
        {
            set_my_op_tok_error(my_div_error(line_number));
            return;
        }
        (*my_stack)->next->next->num %= (*my_stack)->next->num;
        my_pop(my_stack, line_number);
    }
    else
        set_my_op_tok_error(my_short_stack_error(line_number, "mod"));
}
