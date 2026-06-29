calc.c
======

calc\_eval
----------

.. code-block:: c

   CalcStatus calc_eval(const char *expr, double *out)

Evaluate an infix arithmetic expression.

The \`calc\_eval\` function evaluates an infix arithmetic expression provided as a NUL-terminated string. It processes the expression using lexical analysis, checks for balanced parentheses, and then parses and evaluates the expression. The result of the evaluation is stored in the memory location pointed to by \`out\`. The function returns a \`CalcStatus\` value indicating whether the operation was successful or if an error occurred. Common error statuses include syntax errors, division by zero, and overflow.


check\_balanced
---------------

.. code-block:: c

   static CalcStatus check_balanced(const Token *tokens, int count)

Check if parentheses in the given token array are balanced.

This function iterates through an array of tokens, checking for balanced use of parentheses. It uses a stack to keep track of opening parentheses. For each token, if it is an opening parenthesis, it is pushed onto the stack. If it is a closing parenthesis, the function attempts to pop from the stack. If the stack is empty when a closing parenthesis is encountered, or if the stack overflows during this process, the function returns an error status. After processing all tokens, if the stack is empty, it indicates that all parentheses were matched correctly, and the function returns \`CALC\_OK\`. Otherwise, it returns \`CALC\_ERR\_SYNTAX\`, indicating unbalanced parentheses.

:returns: The function returns \`CALC\_OK\` if all parentheses are balanced, otherwise it returns \`CALC\_ERR\_SYNTAX\` if there are unmatched parentheses or \`CALC\_ERR\_OVERFLOW\` if the stack overflows.

