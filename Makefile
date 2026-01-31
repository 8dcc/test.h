
CC=gcc
CFLAGS=-ansi -Wall -Wextra -Wpedantic -Wshadow -ggdb3

TEST_BIN=example_test.out

#-------------------------------------------------------------------------------

.PHONY: all test clean

all: $(TEST_BIN)

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN) obj/*.o

#-------------------------------------------------------------------------------

$(TEST_BIN): src/example.c src/test.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ src/example.c

obj/%.c.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<
