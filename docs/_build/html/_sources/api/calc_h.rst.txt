calc.h
======

CalcStatus
----------

.. code-block:: c

   enum CalcStatus { CALC_OK, CALC_ERR_SYNTAX, CALC_ERR_DIV_ZERO, CALC_ERR_OVERFLOW, CALC_ERR_UNKNOWN_OP }

Enum representing the status of a calculation operation.

This enumeration is used to indicate the result of a calculation operation performed by a calculator system. Each value corresponds to a specific type of error or completion state.

:member CALC\_OK: Indicates that the calculation was successful and no errors occurred.
:member CALC\_ERR\_SYNTAX: Indicates that there was a syntax error in the input expression.
:member CALC\_ERR\_DIV\_ZERO: Indicates that an attempt was made to divide by zero.
:member CALC\_ERR\_OVERFLOW: Indicates that the result of the calculation exceeded the maximum representable value.
:member CALC\_ERR\_UNKNOWN\_OP: Indicates that an unknown operator was encountered in the input expression.

TokenType
---------

.. code-block:: c

   enum TokenType { TOK_NUMBER, TOK_OP, TOK_LPAREN, TOK_RPAREN, TOK_END }

Represents different types of tokens used in a calculator expression.

The \`TokenType\` enumeration defines various token types that can be encountered while parsing an arithmetic expression in a calculator application. Each type corresponds to a specific kind of token and is used to identify and process different elements of the input expression.

:member TOK\_NUMBER: Indicates that the token represents a numeric value.
:member TOK\_OP: Denotes that the token is an operator such as +, -, \*, /.
:member TOK\_LPAREN: Signifies the start of a parenthesis group in the expression.
:member TOK\_RPAREN: Marks the end of a parenthesis group in the expression.
:member TOK\_END: Used to indicate the end of the token stream, typically after processing all tokens.

Token
-----

.. code-block:: c

   struct Token { TokenType type; double number; char op; }

Represents a token in an expression for calculation purposes.

The \`Token\` structure is used to store individual tokens from an expression that needs to be evaluated. Each token can represent either a numeric value, an operator, or a special type of token like parentheses.

:member type: Indicates the type of the token. This can be one of several predefined types such as \`NUMBER\`, \`OPERATOR\`, \`LPAREN\`, \`RPAREN\`, etc.
:member number: Stores the numeric value if the token represents a number. If the token is not a number, this field should not be accessed.
:member op: Stores the character representing the operator if the token is an operator. If the token is not an operator, this field should not be accessed.

