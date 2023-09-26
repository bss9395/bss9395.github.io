SRC=$(wildcard ./src/*.c)
OBJ=$(patsubst ./src/%.c, ./obj/%.o, $(SRC))
INC=./inc

CC=gcc
CFLAGS=-c
TARGET=./bin/main

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

./obj/%.o: ./src/%.c
	$(CC) $(CFLAGS) -I$(INC) $< -o $@

clean:
	rm $(OBJ) $(TARGET)

