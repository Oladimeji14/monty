#include "monty.h"

void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);
void convert_to_stack(stack_t **stack, unsigned int line_number);
void convert_to_queue(stack_t **stack, unsigned int line_number);

void rotate_left(stack_t **stack, unsigned int line_number) {
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;

    (void)line_number;
}

void rotate_right(stack_t **stack, unsigned int line_number) {
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;

    (void)line_number;
}

void convert_to_stack(stack_t **stack, unsigned int line_number) {
    (*stack)->n = STACK;
    (void)line_number;
}

void convert_to_queue(stack_t **stack, unsigned int line_number) {
    (*stack)->n = QUEUE;
    (void)line_number;
}
