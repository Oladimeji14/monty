#ifndef __MY_CUSTOM_HEADER_H__
#define __MY_CUSTOM_HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MY_STACK 0
#define MY_QUEUE 1
#define MY_DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **my_op_toks;

/**
 * struct my_stack_s - doubly linked list representation of a stack (or queue)
 * @num: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct my_stack_s
{
    int num;
    struct my_stack_s *prev;
    struct my_stack_s *next;
} my_stack_t;

/**
 * struct my_instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct my_instruction_s
{
    char *opcode;
    void (*func)(my_stack_t **my_stack, unsigned int line_number);
} my_instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_my_stack(my_stack_t **my_stack);
int init_my_stack(my_stack_t **my_stack);
int check_my_mode(my_stack_t *my_stack);
void free_my_tokens(void);
unsigned int my_token_arr_len(void);
int run_my_monty(FILE *my_script_fd);
void set_my_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void my_monty_push(my_stack_t **my_stack, unsigned int line_number);
void my_monty_pall(my_stack_t **my_stack, unsigned int line_number);
void my_monty_pint(my_stack_t **my_stack, unsigned int line_number);
void my_monty_pop(my_stack_t **my_stack, unsigned int line_number);
void my_monty_swap(my_stack_t **my_stack, unsigned int line_number);
void my_monty_add(my_stack_t **my_stack, unsigned int line_number);
void my_monty_nop(my_stack_t **my_stack, unsigned int line_number);
void my_monty_sub(my_stack_t **my_stack, unsigned int line_number);
void my_monty_div(my_stack_t **my_stack, unsigned int line_number);
void my_monty_mul(my_stack_t **my_stack, unsigned int line_number);
void my_monty_mod(my_stack_t **my_stack, unsigned int line_number);
void my_monty_pchar(my_stack_t **my_stack, unsigned int line_number);
void my_monty_pstr(my_stack_t **my_stack, unsigned int line_number);
void my_monty_rotl(my_stack_t **my_stack, unsigned int line_number);
void my_monty_rotr(my_stack_t **my_stack, unsigned int line_number);
void my_monty_stack(my_stack_t **my_stack, unsigned int line_number);
void my_monty_queue(my_stack_t **my_stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **my_strtow(char *str, char *delims);
char *my_get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int my_usage_error(void);
int my_malloc_error(void);
int my_f_open_error(char *filename);
int my_unknown_op_error(char *opcode, unsigned int line_number);
int my_no_int_error(unsigned int line_number);
int my_pop_error(unsigned int line_number);
int my_pint_error(unsigned int line_number);
int my_short_stack_error(unsigned int line_number, char *op);
int my_div_error(unsigned int line_number);
int my_pchar_error(unsigned int line_number, char *message);

#endif /* __MY_CUSTOM_HEADER_H__ */
