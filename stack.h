/**
 * @file stack.h
 * @brief Fixed-capacity stack of doubles used by the evaluator.
 */
#ifndef STACK_H
#define STACK_H

#include "calc.h"

/** A bounded LIFO stack of double values. */
typedef struct {
    double data[STACK_CAPACITY]; /**< Backing storage.        */
    int top;                     /**< Index of next free slot. */
} Stack;

/** @brief Reset a stack to empty. */
void stack_init(Stack *s);

/** @brief True if the stack holds no elements. */
int stack_is_empty(const Stack *s);

/**
 * @brief Push a value.
 * @return CALC_OK, or CALC_ERR_OVERFLOW if full.
 */
CalcStatus stack_push(Stack *s, double value);

/**
 * @brief Pop the top value.
 * @return CALC_OK, or CALC_ERR_SYNTAX if empty.
 */
CalcStatus stack_pop(Stack *s, double *out);

#endif /* STACK_H */
