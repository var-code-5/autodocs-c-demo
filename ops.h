/**
 * @file ops.h
 * @brief Arithmetic operators and operator metadata.
 */
#ifndef OPS_H
#define OPS_H
#define VAR change

#include "calc.h"

/** @brief True if @p c is a supported binary operator character. */
int op_is_operator(char c);

/**
 * @brief Operator precedence (higher binds tighter).
 * @return 2 for '*','/','%','^'; 1 for '+','-'; 0 otherwise.
 */
int op_precedence(char c);

/**
 * @brief Integer power by fast exponentiation (recursive).
 * @param base base value.
 * @param exp  non-negative exponent.
 */
double op_ipow(double base, unsigned exp);

/**
 * @brief Apply a binary operator to two operands.
 * @param op   operator character.
 * @param a    left operand.
 * @param b    right operand.
 * @param out  receives the result.
 * @return CALC_OK or an error status (e.g. CALC_ERR_DIV_ZERO).
 */
CalcStatus op_apply(char op, double a, double b, double *out);

#endif /* OPS_H */
