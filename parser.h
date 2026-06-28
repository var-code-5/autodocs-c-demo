/**
 * @file parser.h
 * @brief Recursive-descent parser/evaluator over a token stream.
 */
#ifndef PARSER_H
#define PARSER_H

#include "calc.h"

/** Parser cursor over a tokenized expression. */
typedef struct {
    const Token *tokens; /**< Token array (TOK_END terminated). */
    int pos;             /**< Current token index.              */
} Parser;

/**
 * @brief Parse and evaluate a full expression (handles + and -).
 *
 * Mutually recursive with parser_parse_term / parser_parse_factor to honour
 * operator precedence and parentheses.
 *
 * @param ps  parser state.
 * @param out receives the evaluated value.
 * @return CALC_OK or an error status.
 */
CalcStatus parser_parse_expression(Parser *ps, double *out);

/** @brief Parse a term (handles * / % ^). */
CalcStatus parser_parse_term(Parser *ps, double *out);

/** @brief Parse a factor (number, parenthesised expression, unary minus). */
CalcStatus parser_parse_factor(Parser *ps, double *out);

#endif /* PARSER_H */
