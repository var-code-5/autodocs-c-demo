/**
 * @file lexer.h
 * @brief Tokenizer: turns an expression string into a Token array.
 */
#ifndef LEXER_H
#define LEXER_H

#include "calc.h"

/**
 * @brief Tokenize an expression.
 * @param expr   NUL-terminated input.
 * @param tokens output array (at least @p max entries).
 * @param max    capacity of @p tokens.
 * @param count  receives the number of tokens written (incl. TOK_END).
 * @return CALC_OK, CALC_ERR_OVERFLOW, or CALC_ERR_SYNTAX.
 */
CalcStatus lexer_tokenize(const char *expr, Token *tokens, int max, int *count);

#endif /* LEXER_H */
