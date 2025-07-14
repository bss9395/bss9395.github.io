
src_c=$(wildcard *.c)
obj_c=$(patsubst %.c, %, $(src_c))
src_cpp=$(wildcard *.cpp)
obj_cpp=$(patsubst %.cpp, %, $(src_cpp))

all : $(obj_c) $(obj_cpp)
	@#echo $(obj_cpp)

%:%.c
	gcc $< -o $@

%:%.cpp
	g++ $< -o $@

clean:
	rm $(obj_c)
	rm $(obj_cpp)
