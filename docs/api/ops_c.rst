ops.c
=====

op\_apply
---------

.. code-block:: c

   CalcStatus op_apply(char op, double a, double b, double *out)

Applies a binary operator to two operands.

The \`op\_apply\` function takes a character representing a binary operator (\`op\`) and two double precision floating-point numbers (\`a\` and \`b\`). It applies the specified operator to these operands and stores the result in the memory location pointed to by \`out\`. The function returns a value from the \`CalcStatus\` enumeration indicating whether the operation was successful or if an error occurred. Supported operators include addition (+), subtraction (-), multiplication (\*), exponentiation (^), division (/), and modulo (%). Division and modulo operations check for division by zero and return an appropriate error status if such a condition occurs.


op\_ipow
--------

.. code-block:: c

   double op_ipow(double base, unsigned exp)

Computes the integer power of a number using fast exponentiation (recursive).

This function calculates the result of raising a given base to an unsigned integer exponent using an efficient recursive algorithm known as fast exponentiation. The function handles the case where the exponent is zero by returning 1.0, as any number raised to the power of zero is one. For positive exponents, it recursively computes the square of the base raised to half the exponent and adjusts for odd exponents by multiplying the result by the base.


op\_is\_operator
----------------

.. code-block:: c

   int op_is_operator(char c)

Determines if the given character is a supported binary operator.

This function checks whether the input character \`c\` is one of the following binary operators: '+', '-', '\*', '/', '%', or '^'. It returns 1 (true) if \`c\` is a supported operator, and 0 (false) otherwise.


op\_precedence
--------------

.. code-block:: c

   int op_precedence(char c)

Determines the precedence level of an operator.

This function returns an integer representing the precedence level of the given operator character. Higher values indicate that the operator binds more tightly. The precedence levels are as follows: '^' has a precedence of 3, '\*' and '/' have a precedence of 2, '+' and '-' have a precedence of 1, and all other characters have a precedence of 0.


