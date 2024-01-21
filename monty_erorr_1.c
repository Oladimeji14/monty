#include "monty.h"

int usage_err(void);
int malloc_err(void);
int fopen_err(char *filename);
int unknown_op_err(char *opcode, unsigned int line);
int no_int_err(unsigned int line);

int usage_err(void) {
    fprintf(stderr, "USAGE: monty file\n");
    return EXIT_FAILURE;
}

int malloc_err(void) {
    fprintf(stderr, "Error: malloc failed\n");
    return EXIT_FAILURE;
}

int fopen_err(char *fname) {
    fprintf(stderr, "Error: Can't open file %s\n", fname);
    return EXIT_FAILURE;
}

int unknown_op_err(char *op, unsigned int line) {
    fprintf(stderr, "L%u: unknown instruction %s\n", line, op);
    return EXIT_FAILURE;
}

int no_int_err(unsigned int line) {
    fprintf(stderr, "L%u: usage: push integer\n", line);
    return EXIT_FAILURE;
}
