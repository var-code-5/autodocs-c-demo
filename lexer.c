/**
 * @file lexer.c
 * @brief Tokenizer implementation. Uses util_* helpers and ops metadata.
 */
#include "lexer.h"
#include "ops.h"
#include "util.h"

CalcStatus lexer_tokenize(const char *expr, Token *tokens, int max, int *count) {
    int n = 0;
    const char *p = expr;

    while (*p != '\0') {
        p = util_skip_spaces(p);
        if (*p == '\0') {
            break;
        }
        if (n >= max - 1) {
            return CALC_ERR_OVERFLOW;
        }

        if (*p == '(') {
            tokens[n++].type = TOK_LPAREN;
            p++;
        } else if (*p == ')') {
            tokens[n++].type = TOK_RPAREN;
            p++;
        } else if (op_is_operator(*p)) {
            tokens[n].type = TOK_OP;
            tokens[n].op = *p;
            n++;
            p++;
        } else if ((*p >= '0' && *p <= '9') || *p == '.') {
            double value;
            const char *end;
            CalcStatus st = util_parse_number(p, &value, &end);
            if (st != CALC_OK) {
                return st;
            }
            tokens[n].type = TOK_NUMBER;
            tokens[n].number = value;
            n++;
            p = end;
        } else {
            return CALC_ERR_SYNTAX;
        }
    }

    tokens[n].type = TOK_END;
    *count = n + 1;
    return CALC_OK;
}
