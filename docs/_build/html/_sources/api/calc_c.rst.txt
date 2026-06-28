calc.c
======

calc_eval
---------

.. code-block:: c

   CalcStatus calc_eval(const char *expr, double *out)

Evaluate an infix arithmetic expression.

The \`calc\_eval\` function evaluates an infix arithmetic expression provided as a NUL-terminated string. It processes the expression by first tokenizing it into individual components, checking for balanced parentheses, and then parsing and evaluating the expression. On successful evaluation, the result is stored in the location pointed to by \`out\`. The function returns a \`CalcStatus\` value indicating whether the operation was successful or if an error occurred, such as syntax errors or division by zero.


check_balanced
--------------

.. code-block:: c

   static CalcStatus check_balanced(const Token *tokens, int count)

Check if parentheses in the token array are balanced.

The function iterates through the given array of tokens, using a stack to track the balance of parentheses. For each token, if it is an opening parenthesis, it is pushed onto the stack. If it is a closing parenthesis, the function attempts to pop from the stack. If the stack is empty when a closing parenthesis is encountered, or if the stack overflows during the process, the function returns an error status. After processing all tokens, if the stack is empty, it indicates that all parentheses were matched correctly, and the function returns \`CALC\_OK\`. Otherwise, it returns \`CALC\_ERR\_SYNTAX\`, indicating an imbalance.


