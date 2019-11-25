# Makefile
# Author: BSS9395
# Update: 2019-11-04T20:28 +08 @ ShenZhen +08
# Design: GNU Makefile

################################################################################

INCLUDE = Makefile src inc lib lib64
EXCLUDE = .git**

NET = 192.168.12
HST = $(shell echo $$(sudo ifconfig) | grep -o "$(NET).[0-9]*" | tail -n 1)
RMT = $(shell echo $$(sudo nmap -sP "$(NET).0/24") | grep -o "$(NET).[0-9]*" | grep -v "$(HST) " | tail -n 1)
MAP = hosts.nmap

################################################################################

USR := $(shell whoami)
PWD := $(shell pwd)
INC := inc
LIB := lib64
SRC := src
LNK := lnk
OUT := out
DST := ~/bin

CSRC := $(shell find $(SRC) -maxdepth 1 -type f \( -false -or -name "*.c" -or -name "*.cpp" -or -name "*.cc" \) -printf "%P ")
CLNK := $(filter-out $(CSRC),$(CSRC:%.c=%.c.o) $(CSRC:%.cpp=%.cpp.o) $(CSRC:%.cc=%.cc.o))
CLIB := #libcrypto.so.10 libssl.so.10
COUT := odbc.out fcgi.out Main.out

################################################################################

LIBRARY_PATH    := #
LD_LIBRARY_PATH := #

GCC      := gcc -m64 -std=c99
GPP      := g++ -m64 -std=c++11
GXX      := $(if $(findstring .cpp,$(CSRC)),$(GPP),$(GCC))
CPPFLAGS := $(INC:%=-I%) $(LIB:%=-L%)
LDFLAGS  := -lpthread -lprotobuf -lfcgi -lmysqlcppconn
CFLAGS   := $(CPPFLAGS) $(LDFLAGS) -Wall # -Werror # -ggdb -g
CLNKS    := $(if $(findstring .o,$(CLNK)),$(CFLAGS),)

################################################################################

vpath %.h   $(INC)
vpath %.hpp $(INC)
vpath %.c   $(SRC)
vpath %.cpp $(SRC)
vpath %.cc  $(SRC)
vpath %.so  $(LIB)
vpath %.a   $(LIB)
vpath %.o   $(LIB)
vpath %     $(LIB)

.PHONY: all run stop check clean purge install uninstall get put sync

all: $(COUT)
#	echo $(COUT) $(CLNK) $(CLNKS)

CMAIN  = $(@F).o               $(@F).so                  $(@F).a
CMAIN += $(@F).c.o             $(@F).c.so                $(@F).c.a
CMAIN += $(@F).cpp.o           $(@F).cpp.so              $(@F).cpp.a
CMAIN += $(@F).cc.o            $(@F).cc.so               $(@F).cc.a
CMAIN += $(*F).o            lib$(*F).so               lib$(*F).a
CMAIN += $(*F).c.o          lib$(*F).c.so             lib$(*F).c.a
CMAIN += $(*F).cpp.o        lib$(*F).cpp.so           lib$(*F).cpp.a
CMAIN += $(*F).cc.o         lib$(*F).cc.so            lib$(*F).cc.a

CXTRS  = $(COUT:%=%.o)         $(COUT:%=lib%.so)         $(COUT:%=lib%.a)
CXTRS += $(COUT:%=%.c.o)       $(COUT:%=lib%.c.so)       $(COUT:%=lib%.c.a)
CXTRS += $(COUT:%=%.cpp.o)     $(COUT:%=lib%.cpp.so)     $(COUT:%=lib%.cpp.a)
CXTRS += $(COUT:%=%.cc.o)      $(COUT:%=lib%.cc.so)      $(COUT:%=lib%.cc.a)
CXTRS += $(COUT:%.out=%.o)     $(COUT:%.out=lib%.so)     $(COUT:%.out=lib%.a)
CXTRS += $(COUT:%.out=%.c.o)   $(COUT:%.out=lib%.c.so)   $(COUT:%.out=lib%.c.a)
CXTRS += $(COUT:%.out=%.cpp.o) $(COUT:%.out=lib%.cpp.so) $(COUT:%.out=lib%.cpp.a)
CXTRS += $(COUT:%.out=%.cc.o)  $(COUT:%.out=lib%.cc.so)  $(COUT:%.out=lib%.cc.a)

$(COUT): $(CLNK)
	$(GXX) -o $@ $(filter $(CMAIN),$(CLNK)) $(filter-out $(CXTRS),$(CLNK)) $(CFLAGS)
#	$(GXX) -o $@ $(filter $(CMAIN),$(CLNK)) $(filter-out $(CXTRS),$(CLNK)) $(CLNKS)

%.o %.c.o   : %.c
	$(GCC) -c -o $@ $< $(CFLAGS)
%.o %.cpp.o : %.cpp
	$(GPP) -c -o $@ $< $(CFLAGS)
%.o %.cc.o  : %.cc
	$(GPP) -c -o $@ $< $(CFLAGS)

lib%.so lib%.c.so   : %.c
	$(GCC) -shared -fPIC -o $@ $< $(CFLAGS)
lib%.so lib%.cpp.so : %.cpp
	$(GPP) -shared -fPIC -o $@ $< $(CFLAGS)
lib%.so lib%.cc.so  : %.cc
	$(GPP) -shared -fPIC -o $@ $< $(CFLAGS)

lib%.a  lib%.c.a   : %.c
	$(GCC) -static -c -o $@ $< $(CFLAGS)
lib%.a  lib%.cpp.a : %.cpp
	$(GPP) -static -c -o $@ $< $(CFLAGS)
lib%.a  lib%.cc.a  : %.cc
	$(GPP) -static -c -o $@ $< $(CFLAGS)

run: $(COUT)
	export LD_LIBRARY_PATH=$(PWD):$(PWD)/$(LIB); export PATH=$(PWD); cd $(SRC); $(COUT)

run-%: $(COUT)
	export LD_LIBRARY_PATH=$(PWD):$(PWD)/$(LIB); export PATH=$(PWD); cd $(SRC); $*

stop: $(COUT)
	killall $(COUT)

check: $(COUT)
	@#nm $(COUT)
	ldd  $(COUT)

clean:
	clear
	@find ./ -maxdepth 1 \( -false $(CLNK:%=-or -name %) \) -printf "rm -r %p\n" -exec rm -r {} +
	@find ./ -maxdepth 1 \( -false $(COUT:%=-or -name %) \) -printf "rm -r %p\n" -exec rm -r {} +

purge: clean
	@find ./            -maxdepth 1 \( ! -name "Makefile" ! -name ".git*" \) ! -type d -printf "rm -r %p\n" -exec rm -r {} +
	@find $(dir $(OUT)) -maxdepth 1 \(   -name $(notdir $(OUT))           \)           -printf "rm -r %p\n" -exec rm -r {} +
	@find ./            -maxdepth 1 \(   -name $(notdir $(LNK))           \)           -printf "rm -r %p\n" -exec rm -r {} +

install: $(COUT)
	@find ./ -maxdepth 1 \( -false $(CLNK:%=-or -name %) \) -exec rsync -varL {} $(LNK)/ \;
	@find ./ -maxdepth 1 \( -false $(COUT:%=-or -name %) \) -exec rsync -varL {} $(DST)/ \;

uninstall:
	@find $(LNK) -maxdepth 1 \( -false $(CLNK:%=-or -name %) \) -printf "rm -r %p\n" -exec rm -r {} +
	@find $(DST) -maxdepth 1 \( -false $(COUT:%=-or -name %) \) -printf "rm -r %p\n" -exec rm -r {} +

sync: get put


get:
	@printf "$(USR)@$(HST):$(PWD) <--- $(USR)@$(RMT):$(OUT)\n"
	@rsync -varLz -e ssh          $(EXCLUDE:%=--exclude "%") $(USR)@$(RMT):$(OUT)/ $(OUT)/

put: $(CLIB)
	@find ./ -maxdepth 1 \( -false $(COUT:%=-or -name %) \) -exec rsync -arL {} $(OUT)/     \;
	@find ./ -maxdepth 1 \( -false $(CLNK:%=-or -name %) \) -exec rsync -arL {} $(OUT)/lnk/ \;
	@rsync -arL $^ $(OUT)/lnk/

	@printf "$(USR)@$(HST):$(PWD) ---> $(USR)@$(RMT):$(OUT)\n"
	@rsync -varLz -e ssh --delete $(EXCLUDE:%=--exclude "%") $(OUT)/ $(USR)@$(RMT):$(OUT)/

################################################################################

tree:
	tree -L 2

tree-%:
	tree -L 2 $*

grep-%:
	grep --color -n $* -R $(SRC) $(INC)

subl:
	sed -i 's/\xe2\x80\x8b//g' $(shell find $(SRC) -maxdepth 1 \( -name "*.c" -or -name "*.cpp" \) -printf "%p\n")
	subl $(shell find $(SRC) -maxdepth 1 \( -name "*.c" -or -name "*.cpp" \) -printf "%p\n")

vim:
	sed -i 's/\xe2\x80\x8b//g' $(shell find $(SRC) -maxdepth 1 \( -name "*.c" -or -name "*.cpp" \) -printf "%p\n")
	vim  $(shell find $(SRC) -maxdepth 1 \( -name "*.c" -or -name "*.cpp" \) -printf "%p\n")

diffuse:
	diffuse src/Main.c src/old/Main.c

git:
	smerge

mysql:
	mysql -uabc -p1234567 -h$(HST) -Dmysql

ifconfig:
	sudo ifconfig ens33 inet 192.168.100.100
	sudo systemctl stop iptables
	sudo systemctl stop firewalld
	ifconfig ens33

protobuf:
	cd $(SRC); protoc --cpp_out=. *.proto

ps:
	ps aux | grep $(COUT) --color

kill-%:
	kill $*
	ps aux | grep $(COUT) --color

valgrind: $(COUT)
	valgrind --log-file=valgrind.log --leak-check=full --show-reachable=yes --leak-resolution=low $(COUT:%=./%)

docker: Dockerfile
	docker build -t ubuntu .
	docker run -it --network host ubuntu


dump: $(CLIB) $(MAP)
	mkdir -p $(OUT)/lnk
	rsync -arL --exclude $(MAP) $^ $(OUT)/lnk/

$(MAP):
	truncate -s 0  $(MAP)
	echo $(USR) >> $(MAP)
	echo $(HST) >> $(MAP)
	echo $(RMT) >> $(MAP)
