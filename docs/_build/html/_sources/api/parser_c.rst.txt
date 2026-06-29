parser.c
========

parser\_parse\_expression
-------------------------

.. code-block:: c

   CalcStatus parser_parse_expression(Parser *ps, double *out)

Parse and evaluate a full arithmetic expression.

This function parses and evaluates a mathematical expression according to the rules of arithmetic. It handles addition (+), subtraction (-), multiplication (\*), division (/), and exponentiation (^). The function uses mutual recursion with \`parser\_parse\_term\` and \`parser\_parse\_factor\` to respect operator precedence and handle nested expressions within parentheses. The parsed expression's result is stored in the location pointed to by \`out\`. On success, it returns \`CALC\_OK\`; otherwise, it returns an appropriate error status such as \`CALC\_ERR\_SYNTAX\` for syntax errors or \`CALC\_ERR\_DIV\_ZERO\` for division by zero.


parser\_parse\_factor
---------------------

.. code-block:: c

   CalcStatus parser_parse_factor(Parser *ps, double *out)

Parse a single factor in an arithmetic expression.

This function parses a single factor in an arithmetic expression. A factor can be a number, a unary minus, or a parenthesized sub-expression. The parsed factor's value is stored in the location pointed to by \`out\`. On success, it returns \`CALC\_OK\`; otherwise, it returns an appropriate error status such as \`CALC\_ERR\_SYNTAX\` for invalid syntax.


parser\_parse\_term
-------------------

.. code-block:: c

   CalcStatus parser_parse_term(Parser *ps, double *out)

Parse a term in an arithmetic expression.

This function parses a term in an arithmetic expression. A term consists of factors combined using multiplication (\*), division (/), modulus (%), and exponentiation (^). The parsed term's value is stored in the location pointed to by \`out\`. On success, it returns \`CALC\_OK\`; otherwise, it returns an appropriate error status such as \`CALC\_ERR\_SYNTAX\` for invalid syntax.


peek
----

.. code-block:: c

   static const Token * peek(Parser *ps)

Returns the next token in the parser's input without advancing the position.

The \`peek\` function retrieves the current token pointed to by the parser's position indicator without incrementing it. This allows for lookahead operations in parsing algorithms, enabling decisions based on upcoming tokens without consuming them from the stream.


