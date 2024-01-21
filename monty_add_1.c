#include "monty.h"

void push(stack_t **s, unsigned int l);
void print_all(stack_t **s, unsigned int l);
void print_top(stack_t **s, unsigned int l);
void pop(stack_t **s, unsigned int l);
void swap(stack_t **s, unsigned int l);

void push(stack_t **s, unsigned int l)
{
    stack_t *t, *new_s;
    int i;

    new_s = malloc(sizeof(stack_t));
    if (!new_s || !op_toks[1])
    {
        set_op_tok_error(!new_s ? malloc_error() : no_int_error(l));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if ((op_toks[1][i] == '-' && i == 0) || (op_toks[1][i] < '0' || op_toks[1][i] > '9'))
        {
            set_op_tok_error(no_int_error(l));
            return;
        }
    }
    new_s->n = atoi(op_toks[1]);

    t = (*s)->next;
    new_s->prev = *s;
    new_s->next = t;
    if (t)
        t->prev = new_s;
    (*s)->next = new_s;
}

void print_all(stack_t **s, unsigned int l)
{
    stack_t *t = (*s)->next;

    while (t)
    {
        printf("%d\n", t->n);
        t = t->next;
    }
    (void)l;
}

void print_top(stack_t **s, unsigned int l)
{
    if ((*s)->next)
        printf("%d\n", (*s)->next->n);
    else
        set_op_tok_error(pint_error(l));
}

void pop(stack_t **s, unsigned int l)
{
    stack_t *n = (*s)->next->next;

    if ((*s)->next)
    {
        free((*s)->next);
        if (n)
            n->prev = *s;
        (*s)->next = n;
    }
    else
        set_op_tok_error(pop_error(l));
}

void swap(stack_t **s, unsigned int l)
{
    stack_t *t;

    if ((*s)->next && (*s)->next->next)
    {
        t = (*s)->next->next;
        (*s)->next->next = t->next;
        (*s)->next->prev = t;
        if (t->next)
            t->next->prev = (*s)->next;
        t->next = (*s)->next;
        t->prev = *s;
        (*s)->next = t;
    }
    else
        set_op_tok_error(short_stack_error(l, "swap"));
}
