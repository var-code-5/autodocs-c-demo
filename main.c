/**
 * @file main.c
 * @brief Command-line front end: `calc "1 + 2 * (3 - 4)"`.
 */
#include "calc.h"
#include "util.h"

#include <stdio.h>
#include <string.h>

/** @brief Join argv[1..argc-1] into a single space-separated expression. */
static void join_args(int argc, char **argv, char *buf, size_t cap) {
    buf[0] = '\0';
    size_t len = 0;
    for (int i = 1; i < argc && len < cap - 1; i++) {
        if (i > 1 && len < cap - 1) {
            buf[len++] = ' ';
        }
        size_t arglen = strlen(argv[i]);
        if (len + arglen >= cap) {
            arglen = cap - 1 - len;
        }
        memcpy(buf + len, argv[i], arglen);
        len += arglen;
    }
    buf[len] = '\0';
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s EXPR   e.g. %s \"1 + 2 * (3 - 4)\"\n", argv[0], argv[0]);
        fprintf(stderr, "calc %s\n", CALC_VERSION);
        return 2;
    }

    char expr[512];
    join_args(argc, argv, expr, sizeof expr);

    double result;
    CalcStatus st = calc_eval(expr, &result);
    if (st != CALC_OK) {
        fprintf(stderr, "error: %s\n", util_status_message(st));
        return 1;
    }

    printf("%g\n", result);
    return 0;
}
