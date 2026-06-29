parser.h
========

Parser
------

.. code-block:: c

   struct Parser { const Token * tokens; int pos; }

Represents a parser for handling token streams.

The \`Parser\` structure is designed to manage the parsing of a sequence of tokens. It contains two main members that facilitate this process.

:member tokens: A pointer to an array of \`Token\` structures representing the input tokens to be parsed.
:member pos: An integer indicating the current position within the \`tokens\` array. This helps track where the parser is in the input stream.

