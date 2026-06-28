/**
 * @file calc.h
 * @brief Public API and shared types for the calc expression evaluator.
 *
 * calc parses and evaluates simple infix arithmetic expressions such as
 * "1 + 2 * (3 - 4)" using a hand-written tokenizer and a recursive-descent
 * parser backed by a value stack.
 */
#ifndef CALC_H
#define CALC_H

#include <stddef.h>

/** Library version string. */
#define CALC_VERSION "1.0.0"

/** Maximum number of tokens accepted in a single expression. */
#define MAX_TOKENS 256

/** Maximum depth of the evaluation value stack. */
#define STACK_CAPACITY 128

/** Largest of two values (function-like macro). */
#define CALC_MAX(a, b) ((a) > (b) ? (a) : (b))

/** Result status codes returned across the API. */
typedef enum {
    CALC_OK = 0,          /**< Evaluation succeeded.            */
    CALC_ERR_SYNTAX,      /**< Malformed expression.            */
    CALC_ERR_DIV_ZERO,    /**< Division or modulo by zero.      */
    CALC_ERR_OVERFLOW,    /**< Token/stack capacity exceeded.   */
    CALC_ERR_UNKNOWN_OP   /**< Operator not recognised.         */
} CalcStatus;

/** Kind of a lexical token. */
typedef enum {
    TOK_NUMBER,   /**< A numeric literal.        */
    TOK_OP,       /**< A binary operator.        */
    TOK_LPAREN,   /**< '('                       */
    TOK_RPAREN,   /**< ')'                       */
    TOK_END       /**< End of input sentinel.    */
} TokenType;

/** A single lexical token produced by the lexer. */
typedef struct {
    TokenType type;  /**< Discriminates the union below.        */
    double number;   /**< Value when @ref type is TOK_NUMBER.   */
    char op;         /**< Operator char when @ref type TOK_OP.  */
} Token;

/**
 * @brief Evaluate an infix arithmetic expression.
 * @param expr  NUL-terminated expression string.
 * @param out   Receives the result on success.
 * @return CALC_OK or an error status.
 */
CalcStatus calc_eval(const char *expr, double *out);

#endif /* CALC_H */
