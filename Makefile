CC      ?= cc
CFLAGS  ?= -std=c99 -Wall -Wextra -O2
SRcS    := calc.c ops.c stack.c lexer.c parser.c util.c main.c
OBJS    := $(SRcS:.c=.o)
BIN     := calc

.PHONY: all clean test

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(BIN)
	@./$(BIN) "1 + 2 * 3" | grep -qx 7 && echo "pass: 1 + 2 * 3 = 7"
	@./$(BIN) "2 ^ 10" | grep -qx 1024 && echo "pass: 2 ^ 10 = 1024"
	@./$(BIN) "(1 + 2) * (3 - 4)" | grep -qx -- -3 && echo "pass: (1 + 2) * (3 - 4) = -3"

clean:
	rm -f $(OBJS) $(BIN)
