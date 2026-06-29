calc.c
======

calc\_eval
----------

.. code-block:: c

   CalcStatus calc_eval(const char *expr, double *out)

Evaluate an infix arithmetic expression.

The \`calc\_eval\` function takes a NUL-terminated expression string (\`expr\`) and computes its result, storing it in the memory location pointed to by \`out\`. The function first tokenizes the input expression using the \`lexer\_tokenize\` function. It then checks if the parentheses in the tokenized expression are balanced using the \`check\_balanced\` function. If the parentheses are balanced, the function proceeds to parse and evaluate the expression using the \`parser\_parse\_expression\` function. If any step fails, the function returns an appropriate error status. If the entire input is successfully consumed and evaluated, the function returns \`CALC\_OK\`. This function is crucial for evaluating arithmetic expressions in applications requiring mathematical computation.


check\_balanced
---------------

.. code-block:: c

   static CalcStatus check_balanced(const Token *tokens, int count)

Check if parentheses in the given token array are balanced.

The function \`check\_balanced\` verifies that the parentheses in the input token array are balanced. It uses a stack to keep track of the opening parentheses. For each token, if it is an opening parenthesis (\`TOK\_LPAREN\`), it is pushed onto the stack. If it is a closing parenthesis (\`TOK\_RPAREN\`), the function attempts to pop an element from the stack. If the stack is empty when a closing parenthesis is encountered, or if there are still elements left on the stack after processing all tokens, the function returns \`CALC\_ERR\_SYNTAX\`, indicating a syntax error. If the stack overflows during the process, it returns \`CALC\_ERR\_OVERFLOW\`. Otherwise, it returns \`CALC\_OK\` if all parentheses are correctly matched.

:returns: Returns \`CALC\_OK\` if the parentheses are balanced, \`CALC\_ERR\_SYNTAX\` if they are not, and \`CALC\_ERR\_OVERFLOW\` if the stack overflows.

