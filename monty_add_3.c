#include "monty.h"

void my_nop(my_stack_t **my_stack, unsigned int line);
void my_pchar(my_stack_t **my_stack, unsigned int line);
void my_pstr(my_stack_t **my_stack, unsigned int line);

void my_nop(my_stack_t **my_stack, unsigned int line) {
    (void)my_stack;
    (void)line;
}

void my_pchar(my_stack_t **my_stack, unsigned int line) {
    if ((*my_stack)->next == NULL) {
        set_my_op_tok_error(my_pchar_error(line, "stack empty"));
        return;
    }
    if ((*my_stack)->next->num < 0 || (*my_stack)->next->num > 127) {
        set_my_op_tok_error(my_pchar_error(line, "value out of range"));
        return;
    }
    printf("%c\n", (*my_stack)->next->num);
}

void my_pstr(my_stack_t **my_stack, unsigned int line) {
    my_stack_t *tmp = (*my_stack)->next;
    while (tmp && tmp->num != 0 && (tmp->num > 0 && tmp->num <= 127)) {
        printf("%c", tmp->num);
        tmp = tmp->next;
    }
    printf("\n");
    (void)line;
}
