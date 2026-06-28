parser.c
========

parser_parse_expression
-----------------------

.. code-block:: c

   CalcStatus parser_parse_expression(Parser *ps, double *out)

Parse and evaluate a full arithmetic expression.

This function parses and evaluates a mathematical expression according to the rules of arithmetic. It handles addition (+), subtraction (-), multiplication (\*), division (/), modulus (%), and exponentiation (^). The function uses mutual recursion with \`parser\_parse\_term\` and \`parser\_parse\_factor\` to respect operator precedence and handle nested expressions within parentheses. If the expression is valid, it calculates the result and stores it in the output parameter \`out\`. If there is a syntax error or any other issue during parsing, it returns an appropriate error status.


parser_parse_factor
-------------------

.. code-block:: c

   CalcStatus parser_parse_factor(Parser *ps, double *out)

Parse a single factor in an arithmetic expression.

This function parses a single factor in an arithmetic expression. A factor can be a number, a unary minus, or a parenthesized sub-expression. If the factor is successfully parsed, it stores the result in the output parameter \`out\`. If there is a syntax error, such as an unexpected token or mismatched parentheses, it returns an error status.


parser_parse_term
-----------------

.. code-block:: c

   CalcStatus parser_parse_term(Parser *ps, double *out)

Parse a term in an arithmetic expression.

This function parses a term in an arithmetic expression. A term consists of factors combined using multiplication (\*), division (/), modulus (%), and exponentiation (^). The function respects operator precedence and handles nested expressions. If the term is successfully parsed, it calculates the result and stores it in the output parameter \`out\`. If there is a syntax error or any other issue during parsing, it returns an appropriate error status.


peek
----

.. code-block:: c

   static const Token * peek(Parser *ps)

Returns the next token in the parser's input without advancing the position.

The \`peek\` function retrieves the current token pointed to by the parser's position indicator without incrementing it. This allows for lookahead operations in parsing algorithms, enabling decisions based on upcoming tokens without consuming them from the stream.


