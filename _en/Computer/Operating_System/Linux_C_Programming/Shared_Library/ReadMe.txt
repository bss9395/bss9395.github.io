### 创建动态库的步骤。

brilliant@machine:~/Desktop/Shared_Library$ g++ -fPIC -c Hello.cpp
brilliant@machine:~/Desktop/Shared_Library$ g++ -shared Hello.o -o libhello.so
brilliant@machine:~/Desktop/Shared_Library$ g++ Main.cpp -L. -lhello
brilliant@machine:~/Desktop/Shared_Library$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
brilliant@machine:~/Desktop/Shared_Library$ ./a.out 
Hello, world!
brilliant@machine:~/Desktop/Shared_Library$ 
