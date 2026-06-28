ops.c
=====

op_apply
--------

.. code-block:: c

   CalcStatus op_apply(char op, double a, double b, double *out)

Applies a binary operator to two operands and stores the result.

The \`op\_apply\` function takes a character representing a binary operator (\`op\`) and two double precision floating-point numbers (\`a\` and \`b\`). It applies the specified operator to these operands and stores the result in the memory location pointed to by \`out\`. The function returns a \`CalcStatus\` indicating whether the operation was successful or if an error occurred, such as division by zero or an unknown operator.

:returns: A \`CalcStatus\` value indicating the success or failure of the operation. Possible values include \`CALC\_OK\` for success, \`CALC\_ERR\_DIV\_ZERO\` for division by zero, and \`CALC\_ERR\_UNKNOWN\_OP\` for an unrecognized operator.

**Side effects:**

- Modifies the memory location pointed to by \`out\` with the result of the operation.

op_ipow
-------

.. code-block:: c

   double op_ipow(double base, unsigned exp)

Computes the integer power of a number using fast exponentiation with recursion.

This function calculates the result of raising a given base to an unsigned integer exponent using an efficient recursive algorithm known as fast exponentiation. The method reduces the time complexity compared to naive repeated multiplication by utilizing the property that a^b can be computed as (a^(b/2))^2 for even b, and a^b = a \* (a^(b-1)) for odd b.


op_is_operator
--------------

.. code-block:: c

   int op_is_operator(char c)

Determines if the given character is a supported binary operator.

This function checks whether the input character \`c\` is one of the following binary operators: '+', '-', '\*', '/', '%', or '^'. It returns 1 (true) if \`c\` is a supported operator, and 0 (false) otherwise.


op_precedence
-------------

.. code-block:: c

   int op_precedence(char c)

Determines the precedence level of an operator.

This function returns an integer representing the precedence level of the given operator character. Higher values indicate that the operator binds more tightly. The precedence levels are as follows: '^' has a precedence of 3, '\*' and '/' have a precedence of 2, '+' and '-' have a precedence of 1, and all other characters have a precedence of 0.


