/**
 * @file util.h
 * @brief Small helpers shared across the lexer and parser.
 */
#ifndef UTIL_H
#define UTIL_H

#include "calc.h"

/**
 * @brief Advance past ASCII spaces and tabs.
 * @param p input cursor.
 * @return pointer to the first non-space character.
 */
const char *util_skip_spaces(const char *p);

/**
 * @brief Parse a decimal number at @p p.
 * @param p   input cursor (must point at a digit or '.').
 * @param out receives the parsed value.
 * @param end set to the first unconsumed character.
 * @return CALC_OK or CALC_ERR_SYNTAX.
 */
CalcStatus util_parse_number(const char *p, double *out, const char **end);

/** @brief Human-readable message for a status code. */
const char *util_status_message(CalcStatus status);

#endif /* UTIL_H */
