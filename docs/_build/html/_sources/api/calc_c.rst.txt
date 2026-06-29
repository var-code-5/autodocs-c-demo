calc.c
======

calc\_eval
----------

.. code-block:: c

   CalcStatus calc_eval(const char *expr, double *out)

Evaluate an infix arithmetic expression.

The \`calc\_eval\` function takes a NUL-terminated string representing an arithmetic expression and evaluates it, storing the result in the location pointed to by \`out\`. The function performs several steps to ensure the expression is valid and computes the correct result. First, it tokenizes the input expression using the \`lexer\_tokenize\` function. Next, it checks for balanced parentheses using the \`check\_balanced\` function. If both steps succeed, the function proceeds to parse and evaluate the expression using the \`parser\_parse\_expression\` function. Finally, it verifies that the entire input has been consumed and returns the evaluation result or an error status if any step fails. This function is crucial for handling user input in applications requiring arithmetic calculations.


check\_balanced
---------------

.. code-block:: c

   static CalcStatus check_balanced(const Token *tokens, int count)

Check if parentheses in the given token array are balanced.

This function iterates through an array of tokens, checking for balanced use of parentheses. It uses a stack to keep track of opening parentheses. For each token, if it is an opening parenthesis, it is pushed onto the stack. If it is a closing parenthesis, the function attempts to pop from the stack. If the stack is empty when a closing parenthesis is encountered, or if the stack overflows during this process, the function returns an error status. After processing all tokens, if the stack is empty, it indicates that all parentheses were matched correctly, and the function returns \`CALC\_OK\`. Otherwise, it returns \`CALC\_ERR\_SYNTAX\`, indicating unbalanced parentheses.

:returns: The function returns \`CALC\_OK\` if all parentheses are balanced, otherwise it returns \`CALC\_ERR\_SYNTAX\` if there are unbalanced parentheses or \`CALC\_ERR\_OVERFLOW\` if the stack overflows.

