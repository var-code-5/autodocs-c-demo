lexer.c
=======

lexer_tokenize
--------------

.. code-block:: c

   CalcStatus lexer_tokenize(const char *expr, Token *tokens, int max, int *count)

Tokenizes an input expression into individual tokens.

The \`lexer\_tokenize\` function takes a NUL-terminated string representing an arithmetic expression and tokenizes it into an array of \`Token\` structures. Each token represents either a number, an operator, a parenthesis, or the end of the expression. The function ensures that the output array does not exceed the specified maximum capacity (\`max\`). Upon completion, it updates the \`count\` parameter with the total number of tokens generated, including the special \`TOK\_END\` token. The function returns a status indicating success or an error condition such as overflow or syntax errors.

:param expr: A NUL-terminated string containing the arithmetic expression to be tokenized.
:param tokens: An array of \`Token\` structures where the resulting tokens will be stored. This array must have at least \`max\` elements allocated.
:param max: The maximum number of tokens that can be stored in the \`tokens\` array. The function will not generate more than this many tokens.
:param count: A pointer to an integer where the function will store the total number of tokens generated, including the \`TOK\_END\` token.
:returns: A \`CalcStatus\` enum indicating the result of the operation. Possible values include \`CALC\_OK\` for success, \`CALC\_ERR\_OVERFLOW\` if the number of tokens exceeds the maximum capacity, and \`CALC\_ERR\_SYNTAX\` if there is a syntax error in the input expression.

