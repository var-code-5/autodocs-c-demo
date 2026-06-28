/**
 * @file util.c
 * @brief Helper implementations.
 */
#include "util.h"

#include <stdlib.h>

const char *util_skip_spaces(const char *p) {
    while (*p == ' ' || *p == '\t') {
        p++;
    }
    return p;
}

CalcStatus util_parse_number(const char *p, double *out, const char **end) {
    char *stop = NULL;
    double v = strtod(p, &stop);
    if (stop == p) {
        return CALC_ERR_SYNTAX;
    }
    *out = v;
    *end = stop;
    return CALC_OK;
}

const char *util_status_message(CalcStatus status) {
    switch (status) {
        case CALC_OK:            return "ok";
        case CALC_ERR_SYNTAX:    return "syntax error";
        case CALC_ERR_DIV_ZERO:  return "division by zero";
        case CALC_ERR_OVERFLOW:  return "expression too large";
        case CALC_ERR_UNKNOWN_OP: return "unknown operator";
        default:                 return "unspecified error";
    }
}
