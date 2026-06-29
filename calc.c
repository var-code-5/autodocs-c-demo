/**
 * @file calc.c
 * @brief Top-level facade: tokenize, validate, then evaluate.
 */
#include "calc.h"
#include "lexer.h"
#include "parser.h"
#include "stack.h"

int mul(int a, int b){ return a*b;}

int add(int a,int b){return a+b;}
/**
 * @brief Verify parentheses are balanced using a value stack.
 * @param tokens token array.
 * @param count  number of tokens (incl. TOK_END).
 * @return CALC_OK or CALC_ERR_SYNTAX / CALC_ERR_OVERFLOW.
 */
static CalcStatus check_balanced(const Token *tokens, int count) {
    Stack depth;
    stack_init(&depth);
    for (int i = 0; i < count; i++) {
        if (tokens[i].type == TOK_LPAREN) {
            if (stack_push(&depth, 1.0) != CALC_OK) {
                return CALC_ERR_OVERFLOW;
            }
        } else if (tokens[i].type == TOK_RPAREN) {
            double tmp;
            if (stack_pop(&depth, &tmp) != CALC_OK) {
                return CALC_ERR_SYNTAX;  /* unmatched ')' */
            }
        }
    }
    return stack_is_empty(&depth) ? CALC_OK : CALC_ERR_SYNTAX;
}

CalcStatus calc_eval(const char *expr, double *out) {
    Token tokens[MAX_TOKENS];
    int count = 0;

    CalcStatus st = lexer_tokenize(expr, tokens, MAX_TOKENS, &count);
    if (st != CALC_OK) {
        return st;
    }

    st = check_balanced(tokens, count);
    if (st != CALC_OK) {
        return st;
    }

    Parser ps = { tokens, 0 };
    st = parser_parse_expression(&ps, out);
    if (st != CALC_OK) {
        return st;
    }

    /* The whole input must be consumed. */
    if (tokens[ps.pos].type != TOK_END) {
        return CALC_ERR_SYNTAX;
    }
    return CALC_OK;
}
