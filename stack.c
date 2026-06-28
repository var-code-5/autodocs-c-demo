/**
 * @file stack.c
 * @brief Implementation of the bounded double stack.
 */
#include "stack.h"

void stack_init(Stack *s) {
    s->top = 0;
}

int stack_is_empty(const Stack *s) {
    return s->top == 0;
}

CalcStatus stack_push(Stack *s, double value) {
    if (s->top >= STACK_CAPACITY) {
        return CALC_ERR_OVERFLOW;
    }
    s->data[s->top++] = value;
    return CALC_OK;
}

CalcStatus stack_pop(Stack *s, double *out) {
    if (stack_is_empty(s)) {
        return CALC_ERR_SYNTAX;
    }
    *out = s->data[--s->top];
    return CALC_OK;
}
