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
CPPFLAGS = -I$(INC) -L. -L$(LNK)
LDFLAGS  = -pthread
CFLAGS   = $(CPPFLAGS) $(LDFLAGS) -Wall -Werror -g -std=c99

################################################################################

.PHONY: all test clean install uninstall

all:$(COBJ)
	gcc $(CFLAGS)    $^ -o $(COUT)

$(COBJ):$(OBJ)/%.o:$(SRC)/%.c
	gcc $(CFLAGS) -c $< -o $@

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
