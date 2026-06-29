stack.h
=======

Stack
-----

.. code-block:: c

   struct Stack { double data[128]; int top; }

A simple stack implementation with fixed capacity.

The \`Stack\` structure represents a last-in-first-out (LIFO) data structure that can hold up to 128 elements of type \`double\`. It includes an array to store the elements and an integer to keep track of the current position of the top element.

:member data: An array of doubles that holds the elements of the stack.
:member top: An integer representing the index of the top element in the stack. When the stack is empty, \`top\` is -1.

