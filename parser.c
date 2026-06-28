/**
 * @file parser.c
 * @brief Recursive-descent evaluator.
 *
 * The three parse_* routines are mutually recursive — parser_parse_factor
 * recurses back into parser_parse_expression for parenthesised sub-expressions
 * — forming a strongly connected component in the call graph.
 */
#include "parser.h"
#include "ops.h"

static const Token *peek(Parser *ps) {
    return &ps->tokens[ps->pos];
}

CalcStatus parser_parse_expression(Parser *ps, double *out) {
    double acc;
    CalcStatus st = parser_parse_term(ps, &acc);
    if (st != CALC_OK) {
        return st;
    }
    while (peek(ps)->type == TOK_OP &&
           (peek(ps)->op == '+' || peek(ps)->op == '-')) {
        char op = peek(ps)->op;
        ps->pos++;
        double rhs;
        st = parser_parse_term(ps, &rhs);
        if (st != CALC_OK) {
            return st;
        }
        st = op_apply(op, acc, rhs, &acc);
        if (st != CALC_OK) {
            return st;
        }
    }
    *out = acc;
    return CALC_OK;
}

CalcStatus parser_parse_term(Parser *ps, double *out) {
    double acc;
    CalcStatus st = parser_parse_factor(ps, &acc);
    if (st != CALC_OK) {
        return st;
    }
    while (peek(ps)->type == TOK_OP && op_precedence(peek(ps)->op) >= 2) {
        char op = peek(ps)->op;
        ps->pos++;
        double rhs;
        st = parser_parse_factor(ps, &rhs);
        if (st != CALC_OK) {
            return st;
        }
        st = op_apply(op, acc, rhs, &acc);
        if (st != CALC_OK) {
            return st;
        }
    }
    *out = acc;
    return CALC_OK;
}

CalcStatus parser_parse_factor(Parser *ps, double *out) {
    const Token *t = peek(ps);

    if (t->type == TOK_NUMBER) {
        *out = t->number;
        ps->pos++;
        return CALC_OK;
    }
    if (t->type == TOK_OP && t->op == '-') {     /* unary minus */
        ps->pos++;
        double v;
        CalcStatus st = parser_parse_factor(ps, &v);
        if (st != CALC_OK) {
            return st;
        }
        *out = -v;
        return CALC_OK;
    }
    if (t->type == TOK_LPAREN) {
        ps->pos++;
        CalcStatus st = parser_parse_expression(ps, out);  /* recurse */
        if (st != CALC_OK) {
            return st;
        }
        if (peek(ps)->type != TOK_RPAREN) {
            return CALC_ERR_SYNTAX;
        }
        ps->pos++;
        return CALC_OK;
    }
    return CALC_ERR_SYNTAX;
}
