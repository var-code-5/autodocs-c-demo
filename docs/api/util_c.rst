util.c
======

util_parse_number
-----------------

.. code-block:: c

   CalcStatus util_parse_number(const char *p, double *out, const char **end)

Parse a decimal number from the input string starting at \`p\`.

This function attempts to parse a decimal number from the input string pointed to by \`p\`. If successful, it stores the parsed number in the location pointed to by \`out\` and updates \`end\` to point to the first character after the parsed number. The function returns \`CALC\_OK\` on success. If the input does not start with a valid digit or '.', it returns \`CALC\_ERR\_SYNTAX\`. This function is crucial for interpreting numeric values in expressions processed by the lexer.


util_skip_spaces
----------------

.. code-block:: c

   const char * util_skip_spaces(const char *p)

Skip over leading ASCII whitespace characters.

This function advances the input cursor \`p\` past any leading ASCII whitespace characters (spaces and tabs). It returns a pointer to the first non-whitespace character in the string.


util_status_message
-------------------

.. code-block:: c

   const char * util_status_message(CalcStatus status)

Returns a human-readable string describing the given calculation status.

This function takes a \`CalcStatus\` enum value as input and returns a corresponding string that describes the status in a human-readable format. The possible statuses include success (\`CALC\_OK\`), syntax errors (\`CALC\_ERR\_SYNTAX\`), division by zero (\`CALC\_ERR\_DIV\_ZERO\`), overflow (\`CALC\_ERR\_OVERFLOW\`), unknown operators (\`CALC\_ERR\_UNKNOWN\_OP\`), and an unspecified error (\`default\`). This function is utilized by the \`main\` function in \`main.c\` to provide feedback on the outcome of calculations.


