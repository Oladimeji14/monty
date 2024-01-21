#include "monty.h"

void nop(stack_t **stack, unsigned int line);
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);

void nop(stack_t **stack, unsigned int line) {
    (void)stack;
    (void)line;
}

void pchar(stack_t **stack, unsigned int line) {
    if ((*stack)->next == NULL) {
        set_op_tok_error(pchar_error(line, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127) {
        set_op_tok_error(pchar_error(line, "value out of range"));
        return;
    }
    printf("%c\n", (*stack)->next->n);
}

void pstr(stack_t **stack, unsigned int line) {
    stack_t *tmp = (*stack)->next;
    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127)) {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }
    printf("\n");
    (void)line;
}
