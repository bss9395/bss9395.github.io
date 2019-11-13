#include "zinx.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int checkError(const bool failed, const char *file, const long line, const char *func, const char *msg) {
    /* __FILE__:__LINE__:__FUNCTION__:msg:[errno]strerror */
    if(failed) {
        fprintf(stderr, "\e[33m==%s==%ld==%s==%s==[%d]%s==\e[0m\n", file, line, func, msg, errno, strerror(errno));
        if(errno) {
            exit(errno);
        }
    }

    return 0;
}

class StdinChannel : public Ichannel {
public:
    virtual bool Init() {
        checkError(true, "", __LINE__, __FUNCTION__, "");
        return true;
    }

    virtual bool ReadFd(string &input) {
        checkError(true, "", __LINE__, __FUNCTION__, "");

        char buf[1024];
        int ret = read(STDIN_FILENO, buf, sizeof(buf));
        buf[ret] = '\0';

        input = string(buf);
        cout << input << endl;

        return true;
    }

    virtual bool WriteFd(string &output) {
        checkError(true, "", __LINE__, __FUNCTION__, "");
        return false;
    }

    virtual void Fini() {
        checkError(true, "", __LINE__, __FUNCTION__, "");
        return ;
    }

    virtual int GetFd() {
        checkError(true, "", __LINE__, __FUNCTION__, "");
        return STDIN_FILENO;
    }

    virtual string GetChannelInfo() {
        checkError(true, "", __LINE__, __FUNCTION__, "");
        return "StdinChannel";
    }

protected:
    virtual AZinxHandler *GetInputNextStage(BytesMsg &input) {
        checkError(true, "", __LINE__, __FUNCTION__, "");
        return nullptr;
    }
};

int main(int argc, char *argv[]) {
    ZinxKernel::ZinxKernelInit();
    StdinChannel stdinChannel;
    ZinxKernel::Zinx_Add_Channel(stdinChannel);
    ZinxKernel::Zinx_Run();
    ZinxKernel::ZinxKernelFini();

    return 0;
}