main.c
======

join\_args
----------

.. code-block:: c

   static void join_args(int argc, char **argv, char *buf, size_t cap)

Joins command-line arguments into a single space-separated string.

This function takes an array of command-line arguments (\`argv\`) and concatenates them into a single string (\`buf\`), separated by spaces. The resulting string is stored in \`buf\`, which must have sufficient capacity to hold the concatenated result plus a null terminator. The function ensures that no more than \`cap\` characters are written to \`buf\`. If there are fewer than two arguments, \`buf\` will be set to an empty string.


main
----

.. code-block:: c

   int main(int argc, char **argv)

Main entry point of the calculator application.

The \`main\` function serves as the primary entry point for the calculator application. It processes command-line arguments to evaluate an arithmetic expression and prints the result. If the number of arguments is less than two, it displays usage information and exits with a non-zero status. Otherwise, it joins all arguments into a single expression string, evaluates it using the \`calc\_eval\` function, and prints the result. Error handling is included to manage various calculation errors, such as syntax errors or division by zero, by printing appropriate error messages and exiting with a non-zero status. The function also includes version information when no expression is provided.


