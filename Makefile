CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ_DIR = ./objects

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

calculator.exe: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir $@

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) # doesn't work, idk why