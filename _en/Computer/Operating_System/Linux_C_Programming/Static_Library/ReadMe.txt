
### 创建静态库的步骤

brilliant@machine:~/Desktop/Static_Library$ g++ -c Hello.cpp
brilliant@machine:~/Desktop/Static_Library$ ar -crs libhello.a Hello.o
brilliant@machine:~/Desktop/Static_Library$ g++ Main.cpp -L. -lhello
brilliant@machine:~/Desktop/Static_Library$ ./a.out 
Hello, world!

