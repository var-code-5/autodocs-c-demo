main.c
======

join_args
---------

.. code-block:: c

   static void join_args(int argc, char **argv, char *buf, size_t cap)

Joins command-line arguments into a single space-separated string.

This function takes an array of command-line arguments (\`argv\`), starting from the second argument (\`argv[1]\`), and concatenates them into a single string separated by spaces. The resulting string is stored in \`buf\`, which must have at least \`cap\` bytes allocated to avoid buffer overflow. If any argument exceeds the remaining capacity of \`buf\`, it is truncated to fit. The function ensures that the final string is null-terminated.


main
----

.. code-block:: c

   int main(int argc, char **argv)

Main entry point of the calculator program.

The \`main\` function serves as the primary entry point for the calculator program. It accepts command-line arguments and evaluates an arithmetic expression provided as an argument. If no expression is provided, it prints usage instructions and the version of the calculator. The function handles various error conditions, such as syntax errors and division by zero, and outputs the result of the calculation or an error message accordingly.


