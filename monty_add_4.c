#include "monty.h"

void rotate_left(my_stack_t **my_stack, unsigned int line_number);
void rotate_right(my_stack_t **my_stack, unsigned int line_number);
void convert_to_stack(my_stack_t **my_stack, unsigned int line_number);
void convert_to_queue(my_stack_t **my_stack, unsigned int line_number);

void rotate_left(my_stack_t **my_stack, unsigned int line_number) {
    my_stack_t *top, *bottom;

    if ((*my_stack)->next == NULL || (*my_stack)->next->next == NULL)
        return;

    top = (*my_stack)->next;
    bottom = (*my_stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    top->next->prev = *my_stack;
    (*my_stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;

    (void)line_number;
}

void rotate_right(my_stack_t **my_stack, unsigned int line_number) {
    my_stack_t *top, *bottom;

    if ((*my_stack)->next == NULL || (*my_stack)->next->next == NULL)
        return;

    top = (*my_stack)->next;
    bottom = (*my_stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    bottom->prev->next = NULL;
    (*my_stack)->next = bottom;
    bottom->prev = *my_stack;
    bottom->next = top;
    top->prev = bottom;

    (void)line_number;
}

void convert_to_stack(my_stack_t **my_stack, unsigned int line_number) {
    (*my_stack)->num = MY_STACK;
    (void)line_number;
}

void convert_to_queue(my_stack_t **my_stack, unsigned int line_number) {
    (*my_stack)->num = MY_QUEUE;
    (void)line_number;
}
