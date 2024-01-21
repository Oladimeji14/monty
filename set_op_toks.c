#include "monty.h"

void set_error_code(int code) {
    int len = 0, i = 0;
    char *str_code = NULL;
    char **new_tokens = NULL;

    len = token_arr_len();
    new_tokens = malloc(sizeof(char *) * (len + 2));

    if (!op_toks || !new_tokens || !(str_code = get_int(code))) {
        malloc_error();
        free(new_tokens);
        return;
    }

    while (i < len) {
        new_tokens[i] = op_toks[i];
        i++;
    }

    new_tokens[i++] = str_code;
    new_tokens[i] = NULL;

    free(op_toks);
    op_toks = new_tokens;
}
