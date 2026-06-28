main.c
======

join_args
---------

.. code-block:: c

   static void join_args(int argc, char **argv, char *buf, size_t cap)

Joins command-line arguments into a single space-separated string.

This function takes an array of command-line arguments (\`argv\`), starting from the second argument (\`argv[1]\`), and concatenates them into a single string separated by spaces. The resulting string is stored in \`buf\`, which must have a capacity of at least \`cap\` characters to avoid buffer overflow. If any argument exceeds the remaining capacity of \`buf\`, it is truncated to fit. The function ensures that the final string is null-terminated.


main
----

.. code-block:: c

   int main(int argc, char **argv)

Main entry point of the calculator program.

The \`main\` function serves as the primary entry point for the calculator application. It processes command-line arguments to evaluate an arithmetic expression and prints the result. If no expression is provided or if there is an error during evaluation, it outputs an appropriate message and exits with a non-zero status code. The function handles various error conditions, including syntax errors, division by zero, and unknown operators, providing detailed error messages to assist users in correcting their inputs.


