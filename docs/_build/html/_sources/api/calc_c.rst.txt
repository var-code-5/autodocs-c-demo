calc.c
======

calc\_eval
----------

.. code-block:: c

   CalcStatus calc_eval(const char *expr, double *out)

Evaluate an infix arithmetic expression.

The \`calc\_eval\` function takes a NUL-terminated expression string (\`expr\`) and computes its result, storing the result in the location pointed to by \`out\`. The function first tokenizes the input expression using the \`lexer\_tokenize\` function. It then checks for balanced parentheses using the \`check\_balanced\` function. After ensuring the expression is syntactically correct, it parses and evaluates the expression using the \`parser\_parse\_expression\` function. If the entire input is successfully consumed and no errors occur, the function returns \`CALC\_OK\`. Otherwise, it returns an appropriate error status from the \`CalcStatus\` enumeration, such as \`CALC\_ERR\_SYNTAX\` for syntax errors or \`CALC\_ERR\_DIV\_ZERO\` for division by zero.


check\_balanced
---------------

.. code-block:: c

   static CalcStatus check_balanced(const Token *tokens, int count)

Check if parentheses in the given token array are balanced.

This function iterates through an array of tokens, checking for balanced use of parentheses. It uses a stack to keep track of opening parentheses. For each token, if it is an opening parenthesis, it is pushed onto the stack. If it is a closing parenthesis, the function attempts to pop from the stack. If the stack is empty when a closing parenthesis is encountered, or if the stack is not empty after processing all tokens, the function returns an error indicating syntax issues. The function also handles stack overflow errors by returning an appropriate status code.

:returns: The function returns \`CALC\_OK\` if the parentheses are balanced, \`CALC\_ERR\_SYNTAX\` if there are unmatched parentheses, and \`CALC\_ERR\_OVERFLOW\` if the stack overflows during the process.

