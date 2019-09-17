# Makefile example
# Author: BSS9395
# Update: 2019-09-17T23:57 +08 @ ShenZhen +08


# Makefile

INC = inc
SRC = src
OBJ = obj
BIN = bin
ORI = $(wildcard $(SRC)/*.c)

################################################################################

CC       = gcc
CXX      = g++
CPPFLAGS = -I$(INC)
LDFLAGS  = -L.
CFLAGS   = $(CPPFLAGS) $(LDFLAGS) -Wall -Werror -g

################################################################################

.PHONY: all clean install

all:$(ORI:$(SRC)/%.c=$(OBJ)/%.o)
	gcc -o $(BIN)/Main.out $^

$(OBJ)/%.o: $(SRC)/%.c
	gcc -o $@ $(CFLAGS) -c $<

clean:
	rm $(OBJ)/*
	rm $(BIN)/*

install:
	cp $(BIN)/* ~/bin/
