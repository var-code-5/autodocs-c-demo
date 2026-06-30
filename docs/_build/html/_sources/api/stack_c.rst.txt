stack.c
=======

stack\_init
-----------

.. code-block:: c

   void stack_init(Stack *s)

Initialize a stack by setting its top pointer to zero.

This function resets the given stack to an empty state by setting its top pointer to zero. This is typically called before using a stack for the first time or when reusing an existing stack.


stack\_is\_empty
----------------

.. code-block:: c

   int stack_is_empty(const Stack *s)

Determines whether the stack is empty.

This function checks if the stack has any elements by examining the value of the \`top\` member of the \`Stack\` structure. If \`top\` is zero, it means the stack is empty, and the function returns 1 (true). Otherwise, it returns 0 (false).


stack\_pop
----------

.. code-block:: c

   CalcStatus stack_pop(Stack *s, double *out)

Remove and return the top element from the stack.

The \`stack\_pop\` function removes the top element from the given stack and stores it in the location pointed to by \`out\`. If the stack is empty, the function returns \`CALC\_ERR\_SYNTAX\`. Otherwise, it pops the top element and returns \`CALC\_OK\`.


stack\_push
-----------

.. code-block:: c

   CalcStatus stack_push(Stack *s, double value)

Push a value onto the stack.

This function pushes a \`double\` value onto the specified stack. If the stack is already at its capacity (\`STACK\_CAPACITY\`), it returns \`CALC\_ERR\_OVERFLOW\`. Otherwise, it adds the value to the stack and increments the top index, returning \`CALC\_OK\`.


