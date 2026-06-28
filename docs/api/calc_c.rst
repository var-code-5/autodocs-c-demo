calc.c
======

calc_eval
---------

.. code-block:: c

   CalcStatus calc_eval(const char *expr, double *out)

Evaluate an infix arithmetic expression.

The \`calc\_eval\` function takes a NUL-terminated expression string (\`expr\`) and computes its value, storing the result in the location pointed to by \`out\`. The function first tokenizes the input expression using the \`lexer\_tokenize\` function. It then checks for balanced parentheses using the \`check\_balanced\` function. If both steps succeed, the function proceeds to parse and evaluate the expression using the \`parser\_parse\_expression\` function. If the entire input is successfully consumed and parsed without errors, the function returns \`CALC\_OK\`. Otherwise, it returns an appropriate error status such as \`CALC\_ERR\_SYNTAX\` for syntax errors or \`CALC\_ERR\_DIV\_ZERO\` for division by zero.


check_balanced
--------------

.. code-block:: c

   static CalcStatus check_balanced(const Token *tokens, int count)

Check if parentheses in the given token array are balanced.

This function iterates through an array of tokens, checking for balanced use of parentheses. It uses a stack to keep track of opening parentheses. For each token, if it is an opening parenthesis, it is pushed onto the stack. If it is a closing parenthesis, the function attempts to pop from the stack. If the stack is empty when a closing parenthesis is encountered, or if the stack overflows during the process, the function returns an error status. After processing all tokens, if the stack is empty, it indicates that all parentheses were matched correctly, and the function returns \`CALC\_OK\`. Otherwise, it returns \`CALC\_ERR\_SYNTAX\`, indicating unbalanced parentheses.


