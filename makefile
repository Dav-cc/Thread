CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = main.c chunk.c memory.c debug.c
OBJ = $(SRC:%.c=build/%.o)

TARGET = build/clox

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
