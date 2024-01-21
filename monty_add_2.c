#include "custom_monty.h"

void add_op(stack_t **s, unsigned int ln);
void sub_op(stack_t **s, unsigned int ln);
void div_op(stack_t **s, unsigned int ln);
void mul_op(stack_t **s, unsigned int ln);
void mod_op(stack_t **s, unsigned int ln);

void add_op(stack_t **s, unsigned int ln)
{
	if ((*s)->next && (*s)->next->next)
	{
		(*s)->next->next->n += (*s)->next->n;
		pop(s, ln);
	}
	else
		set_op_tok_error(short_stack_error(ln, "add"));
}

void sub_op(stack_t **s, unsigned int ln)
{
	if ((*s)->next && (*s)->next->next)
	{
		(*s)->next->next->n -= (*s)->next->n;
		pop(s, ln);
	}
	else
		set_op_tok_error(short_stack_error(ln, "sub"));
}

void div_op(stack_t **s, unsigned int ln)
{
	if ((*s)->next && (*s)->next->next)
	{
		if ((*s)->next->n == 0)
		{
			set_op_tok_error(div_error(ln));
			return;
		}
		(*s)->next->next->n /= (*s)->next->n;
		pop(s, ln);
	}
	else
		set_op_tok_error(short_stack_error(ln, "div"));
}

void mul_op(stack_t **s, unsigned int ln)
{
	if ((*s)->next && (*s)->next->next)
	{
		(*s)->next->next->n *= (*s)->next->n;
		pop(s, ln);
	}
	else
		set_op_tok_error(short_stack_error(ln, "mul"));
}

void mod_op(stack_t **s, unsigned int ln)
{
	if ((*s)->next && (*s)->next->next)
	{
		if ((*s)->next->n == 0)
		{
			set_op_tok_error(div_error(ln));
			return;
		}
		(*s)->next->next->n %= (*s)->next->n;
		pop(s, ln);
	}
	else
		set_op_tok_error(short_stack_error(ln, "mod"));
}
