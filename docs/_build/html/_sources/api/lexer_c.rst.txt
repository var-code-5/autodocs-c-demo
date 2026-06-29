lexer.c
=======

lexer\_tokenize
---------------

.. code-block:: c

   CalcStatus lexer_tokenize(const char *expr, Token *tokens, int max, int *count)

Tokenizes an input expression into individual tokens.

The \`lexer\_tokenize\` function takes a NUL-terminated input string \`expr\` and tokenizes it into an array of \`Token\` structures stored in \`tokens\`. The maximum capacity of the \`tokens\` array is specified by \`max\`, and the actual number of tokens written, including the special \`TOK\_END\` token, is returned through the \`count\` parameter. The function supports various types of tokens such as parentheses, operators, numbers, and the end-of-expression marker. It handles errors like overflow and syntax issues, returning appropriate error codes defined in the \`CalcStatus\` enum.


