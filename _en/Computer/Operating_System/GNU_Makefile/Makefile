# Makefile example
# Author: BSS9395
# Update: 2019-09-17T23:57 +08 @ ShenZhen +08

################################################################################

INCLUDE := inc lib src Makefile
EXCLUDE := .git**

INC := inc/mysql
LIB := lib/mysql lib/crypto
SRC := src
LNK := lnk
OUT := out

USR := bss9395
HST := $(shell echo $$(ifconfig | grep 'inet ' | head -n 1) | cut -d ' ' -f 2)
DST := ~/bin
RMT := $(shell echo $$(cat ~/.ssh/known_hosts  | head -n 1) | cut -d ' ' -f 1)
DIR := ~/Mine

CSRC := $(shell find $(SRC) -maxdepth 1 -type f -name "*.c" -printf "%P ")
CLNK := $(CSRC:%.c=lib%.c.so)
CLIB := libmysqlclient.so.21 libcrypto.so.10 libssl.so.10
COUT := Main.out

################################################################################

#$ pkg-config --cflags        mysqlclient
#$ pkg-config --libs          mysqlclient
#$ pkg-config --libs --static mysqlclient

LIBRARY_PATH    := #
LD_LIBRARY_PATH := #

CC       := gcc -std=c99 -m64
CXX      := g++ -std=c++ -m64
CPPFLAGS := $(INC:%=-I%) $(LIB:%=-L%)
LDFLAGS  := -lmysqlclient -lcrypto -lssl
CFLAGS   := $(CPPFLAGS) $(LDFLAGS) -Wall # -Werror # -ggdb -g
CLNKS    := $(if $(filter %.o,$(CLNK)),$(CFLAGS),)

################################################################################

vpath %.c  $(SRC)
vpath %.so $(LIB)
vpath %.a  $(LIB)
vpath %    $(LIB)

.PHONY: all run check clean purge install uninstall get put sync

all: $(CLNK)
	$(CC) -o  $(COUT)     $^ $(CLNKS) $(CFLAGS)

%.c.o %.o: %.c
	$(CC) -c            -o $@ $< $(CFLAGS)

lib%.c.so lib%.so: %.c
	$(CC) -shared -fPIC -o $@ $< $(CFLAGS)

lib%.c.a lib%.a: %.c
	$(CC) -static -c    -o $@ $< $(CFLAGS)

run: $(COUT)
	export LD_LIBRARY_PATH=out/lnk; $(COUT:%=./%)

check: $(COUT)
	@#nm $(COUT)
	ldd  $(COUT)

clean:
	@find ./ -maxdepth 1 -false $(CLNK:%=-or -name %) -printf "rm -r %p\n" -exec rm -r {} +
	@find ./ -maxdepth 1 -false $(COUT:%=-or -name %) -printf "rm -r %p\n" -exec rm -r {} +

purge: clean
	@find ./            -maxdepth 1 ! -name "Makefile" ! -name ".git*" ! -type d -printf "rm -r %p\n" -exec rm -r {} +
	@find $(dir $(OUT)) -maxdepth 1   -name $(notdir $(OUT))                     -printf "rm -r %p\n" -exec rm -r {} +
	@find ./            -maxdepth 1   -name $(notdir $(LNK))                     -printf "rm -r %p\n" -exec rm -r {} +

install: $(COUT)
	@find ./ -maxdepth 1 -false $(CLNK:%=-or -name %) -exec rsync -varL {} $(LNK)/ \;
	@find ./ -maxdepth 1 -false $(COUT:%=-or -name %) -exec rsync -varL {} $(DST)/ \;

uninstall:
	@find $(LNK) -maxdepth 1 -false $(CLNK:%=-or -name %) -printf "rm -r %p\n" -exec rm -r {} +
	@find $(DST) -maxdepth 1 -false $(COUT:%=-or -name %) -printf "rm -r %p\n" -exec rm -r {} +

get:
	@printf "$(shell whoami)@$(HST):./ <--- $(USR)@$(RMT):$(DIR)\n"
	@rsync -varLz -e ssh          $(EXCLUDE:%=--exclude "%") $(USR)@$(RMT):$(DIR)/ $(OUT)/

put: $(CLIB)
	@find ./ -maxdepth 1 -false $(COUT:%=-or -name %) -exec rsync -arL {} $(OUT)/     \;
	@find ./ -maxdepth 1 -false $(CLNK:%=-or -name %) -exec rsync -arL {} $(OUT)/lnk/ \;
	@rsync -arL $^ $(OUT)/lnk/

	@printf "$(shell whoami)@$(HST):./ ---> $(USR)@$(RMT):$(DIR)\n"
	@rsync -varLz -e ssh --delete $(EXCLUDE:%=--exclude "%") $(OUT)/ $(USR)@$(RMT):$(DIR)/

sync: get put

################################################################################

subl:
	subl $(shell find src -maxdepth 1 -name "*.c")

vim:
	vim  $(shell find src -maxdepth 1 -name "*.c")

diffuse:
	diffuse src/Main.c src/old/mysql_query.c

git:
	smerge

mysql:
	mysql -uqwe -p1234567 -h$(HST) -Dscott
