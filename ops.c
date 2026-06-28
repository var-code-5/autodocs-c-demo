/**
 * @file ops.c
 * @brief Operator implementations.
 */
#include "ops.h"

int op_is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int op_precedence(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

/* Recursive fast-exponentiation: op_ipow calls itself (self-cycle). */
double op_ipow(double base, unsigned exp) {
    if (exp == 0) {
        return 1.0;
    }
    double half = op_ipow(base, exp / 2);
    double sq = half * half;
    return (exp & 1u) ? sq * base : sq;
}

CalcStatus op_apply(char op, double a, double b, double *out) {
    switch (op) {
        case '+': *out = a + b; return CALC_OK;
        case '-': *out = a - b; return CALC_OK;
        case '*': *out = a * b; return CALC_OK;
        case '^': *out = op_ipow(a, (unsigned)b); return CALC_OK;
        case '/':
            if (b == 0.0) return CALC_ERR_DIV_ZERO;
            *out = a / b;
            return CALC_OK;
        case '%':
            if (b == 0.0) return CALC_ERR_DIV_ZERO;
            *out = (double)((long)a % (long)b);
            return CALC_OK;
        default:
            return CALC_ERR_UNKNOWN_OP;
    }
}
