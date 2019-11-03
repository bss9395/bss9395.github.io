# Makefile
# Author: BSS9395
# Update: 2019-11-03T22:34 +08 @ ShenZhen +08
# Design: GNU Makefile

################################################################################

INCLUDE := Makefile src inc lib lib64
EXCLUDE := .git**

INC := inc
LIB := lib64
SRC := src
LNK := lnk
OUT := out

USR := bss9395
HST := $(shell echo $$(ifconfig | grep 'inet ' | head -n 1) | cut -d ' ' -f 2)
DST := ~/bin
RMT := $(shell echo $$(cat ~/.ssh/known_hosts  | tail -n 1) | cut -d ' ' -f 1)
DIR := ~/Mine

CSRC := $(shell find $(SRC) -maxdepth 1 -type f -name "*.c" -printf "%P ")
CLNK := $(CSRC:%.c=%.o)
CLIB := libcrypto.so.10 libssl.so.10
COUT := Main.out

################################################################################

#$ pkg-config --cflags        mysqlclient
#$ pkg-config --libs          mysqlclient
#$ pkg-config --libs --static mysqlclient

LIBRARY_PATH    := #
LD_LIBRARY_PATH := #

ARCH     := $(if $(findstring 64,$(LIB)),-m64,)
CC       := gcc -std=c99 $(ARCH)
CXX      := g++ -std=c++ $(ARCH)
CPPFLAGS := $(INC:%=-I%) $(LIB:%=-L%)
LDFLAGS  := -lpthread
CFLAGS   := $(CPPFLAGS) $(LDFLAGS) -Wall #-Werror # -ggdb -g
CLNKS    := $(if $(findstring .o,$(CLNK)),$(CFLAGS),)

################################################################################

vpath %.c  $(SRC)
vpath %.so $(LIB)
vpath %.a  $(LIB)
vpath %    $(LIB)

.PHONY: all run stop check clean purge install uninstall get put sync

all: $(COUT)
#	echo $(COUT) $(CLNK) $(CLNKS)

CMAIN  = $(@F).c.o           $(@F).o           $(@F).c.so           $(@F).so            $(@F).c.a       $(@F).a
CMAIN += $(*F).c.o           $(*F).o           $(*F).c.so           $(*F).so            $(*F).c.a       $(*F).a
CXTRS := $(COUT:%=%.c.o)     $(COUT:%=%.o)     $(COUT:%=%.c.so)     $(COUT:%=%.c.o)     $(COUT:%=%.c.a) $(COUT:%=%.a)
CXTRS += $(COUT:%.out=%.c.o) $(COUT:%.out=%.o) $(COUT:%.out=%.c.so) $(COUT:%.out=%.c.o) $(COUT:%.out=%.c.a) $(COUT:%.out=%.a)
$(COUT): $(CLNK)
	$(CC) -o $@ $(filter $(CMAIN),$(CLNK)) $(filter-out $(CXTRS),$(CLNK)) $(CLNKS)

%.c.o        %.o : %.c
	$(CC)            -c -o $@ $< $(CFLAGS)

lib%.c.so lib%.so: %.c
	$(CC) -shared -fPIC -o $@ $< $(CFLAGS)

lib%.c.a  lib%.a : %.c
	$(CC) -static    -c -o $@ $< $(CFLAGS)

run: $(COUT)
	export LD_LIBRARY_PATH=.:lib:lib64; $(COUT:%=./%;)

stop: $(COUT)
	killall $(COUT)

check: $(COUT)
	@#nm $(COUT)
	ldd  $(COUT)

clean:
	clear
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

#	mkdir -p out/lnk; cp -r $(INCLUDE) $(OUT); rsync -arL $^ $(OUT)/lnk/;

	@printf "$(shell whoami)@$(HST):./ ---> $(USR)@$(RMT):$(DIR)\n"
	@rsync -varLz -e ssh --delete $(EXCLUDE:%=--exclude "%") $(OUT)/ $(USR)@$(RMT):$(DIR)/

sync: get put

################################################################################

tree:
	tree -L 2

subl:
	sed -i 's/\xe2\x80\x8b//g' $(shell find src -maxdepth 1 -name "*.c" -printf "%p\n")
	subl $(shell find src -maxdepth 1 -name "*.c" -printf "%p\n")

vim:
	sed -i 's/\xe2\x80\x8b//g' $(shell find src -maxdepth 1 -name "*.c" -printf "%p\n")
	vim  $(shell find src -maxdepth 1 -name "*.c" -printf "%p\n")

diffuse:
	diffuse src/Main.c src/old/Main.c

git:
	smerge

mysql:
	mysql -uqwe -p1234567 -h$(HST) -Dmysql
