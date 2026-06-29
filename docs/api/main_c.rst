main.c
======

join\_args
----------

.. code-block:: c

   static void join_args(int argc, char **argv, char *buf, size_t cap)

Joins command-line arguments into a single space-separated string.

This function takes an array of command-line arguments (\`argv\`) and concatenates them into a single string (\`buf\`), separated by spaces. The resulting string is stored in \`buf\`, which must have sufficient capacity to hold the concatenated result plus a null terminator. The function ensures that no more than \`cap\` characters are written to \`buf\`, preventing buffer overflow.


main
----

.. code-block:: c

   int main(int argc, char **argv)

Main entry point of the calculator program.

The \`main\` function serves as the primary entry point for the calculator program. It accepts command-line arguments and evaluates an arithmetic expression provided as an argument. If no expression is provided, it prints usage instructions and exits with a non-zero status. Otherwise, it joins the command-line arguments into a single string representing the expression, evaluates it using the \`calc\_eval\` function, and prints the result. If an error occurs during evaluation, it prints an error message and exits with a non-zero status. The function handles various error conditions such as syntax errors, division by zero, and overflow, providing appropriate feedback to the user.


