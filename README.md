# calc

A tiny infix arithmetic expression evaluator in C — a multi-file sample project
for exercising the AutoDocs pipeline (cstruct → docgen → render → PR).

```
calc "1 + 2 * (3 - 4)"   # -> -2
calc "2 ^ 10"            # -> 1024
```

## Layout

| File | Responsibility |
|------|----------------|
| `calc.h` | Public API, shared types (`Token`, `CalcStatus`), macros |
| `lexer.c/.h` | Tokenizer (string → `Token[]`) |
| `parser.c/.h` | Recursive-descent evaluator (mutually recursive expr/term/factor) |
| `ops.c/.h` | Operator table + apply + recursive `op_ipow` |
| `stack.c/.h` | Bounded value stack (paren-balance check) |
| `util.c/.h` | Number parsing, status messages |
| `calc.c` | Facade: tokenize → validate → evaluate |
| `main.c` | CLI front end |

The parser's `expression → term → factor → expression` cycle is a deliberate
strongly-connected component for testing call-graph SCC handling.

## Build

```
make           # builds ./calc
make test      # runs a few assertions
```

For the libclang call-graph path, generate `compile_commands.json` with
[bear](https://github.com/rizsotto/Bear): `bear -- make`.
