CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

calculator.exe: $(OBJ_FILES)
    $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
    rm -f calculator.exe $(OBJ_FILES)