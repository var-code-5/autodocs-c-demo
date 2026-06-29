lexer.c
=======

lexer\_tokenize
---------------

.. code-block:: c

   CalcStatus lexer_tokenize(const char *expr, Token *tokens, int max, int *count)

Tokenizes an input expression into individual tokens.

The \`lexer\_tokenize\` function processes a NUL-terminated input string (\`expr\`) and tokenizes it into an array of \`Token\` structures (\`tokens\`). Each token represents a numeric value, operator, parenthesis, or special marker indicating the end of the token list. The function ensures that the output array does not exceed the specified maximum capacity (\`max\`). Upon completion, the function updates the \`count\` parameter with the total number of tokens generated, including the special \`TOK\_END\` marker. The function returns a status code indicating the outcome of the operation, which can be \`CALC\_OK\` for success, \`CALC\_ERR\_OVERFLOW\` if the token count exceeds the maximum allowed, or \`CALC\_ERR\_SYNTAX\` if a syntax error is encountered during tokenization.


