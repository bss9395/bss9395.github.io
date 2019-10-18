# Makefile example
# Author: BSS9395
# Update: 2019-09-17T23:57 +08 @ ShenZhen +08


# Makefile

INC = inc
LNK = inc/lnk
OUT = out
OBJ = out/obj
SRC = src
DST = ~/bin

CSRC = $(wildcard $(SRC)/*.c)
COBJ = $(CSRC:$(SRC)/%.c=$(OBJ)/%.o)
COUT = $(OUT)/Main.out

################################################################################

CC       = gcc
CXX      = g++
CPPFLAGS = -I$(INC) -I$(LNK)
LDFLAGS  = -L. -pthread
CFLAGS   = $(CPPFLAGS) $(LDFLAGS) -Wall -Werror -g -std=c99

################################################################################

.PHONY: all test clean install uninstall

all:$(COBJ)
	gcc -o $(COUT) $(CFLAGS)    $^

$(COBJ):$(OBJ)/%.o:$(SRC)/%.c
	gcc -o $@      $(CFLAGS) -c $<

test:
	$(COUT)

clean:
	rm $(COBJ)
	rm $(COUT)

install:
	mkdir -p $(DST)
	cp $(COUT) $(DST)

uninstall:
	rm $(COUT:$(OUT)/%=$(DST)/%)
