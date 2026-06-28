lexer.c
=======

lexer_tokenize
--------------

.. code-block:: c

   CalcStatus lexer_tokenize(const char *expr, Token *tokens, int max, int *count)

Tokenizes an input expression into individual tokens.

The \`lexer\_tokenize\` function processes a NUL-terminated input string (\`expr\`) and tokenizes it into an array of \`Token\` structures (\`tokens\`). Each token represents a number, operator, parenthesis, or special marker indicating the end of the token list. The function ensures that no more than \`max\` tokens are generated, and it updates the \`count\` parameter to reflect the total number of tokens produced, including the end-of-token marker (\`TOK\_END\`). The function returns a status code indicating whether the operation was successful or if an error occurred during parsing.


