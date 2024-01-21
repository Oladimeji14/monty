#include "monty.h"

int stack_err(unsigned int line, char *op);
int div_err(unsigned int line);
int pop_err(unsigned int line);
int pint_err(unsigned int line);
int pchar_err(unsigned int line, char *msg);

int pop_err(unsigned int line) {
    fprintf(stderr, "L%u: can't pop an empty stack\n", line);
    return EXIT_FAILURE;
}

int pint_err(unsigned int line) {
    fprintf(stderr, "L%d: can't pint, stack empty\n", line);
    return EXIT_FAILURE;
}

int stack_err(unsigned int line, char *op) {
    fprintf(stderr, "L%u: can't %s, stack too short\n", line, op);
    return EXIT_FAILURE;
}

int div_err(unsigned int line) {
    fprintf(stderr, "L%u: division by zero\n", line);
    return EXIT_FAILURE;
}

int pchar_err(unsigned int line, char *msg) {
    fprintf(stderr, "L%u: can't pchar, %s\n", line, msg);
    return EXIT_FAILURE;
}
