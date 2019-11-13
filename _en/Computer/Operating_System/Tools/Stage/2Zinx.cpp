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

class StdoutChannel : public Ichannel {
public:
    virtual bool Init() {
        return true;
    }

    virtual bool ReadFd(string &input) {
        return false;
    }

    virtual bool WriteFd(string &output) {
        cout << output << endl;
        return true;
    }

    virtual void Fini() {
        return ;
    }

    virtual int GetFd() {
        return STDOUT_FILENO;
    }

    virtual string GetChannelInfo() {
        return "StdoutChannel";
    }

    virtual AZinxHandler *GetInputNextStage(BytesMsg &input) {
        return nullptr;
    }
} *stdoutChannel = new StdoutChannel();

class EchoHandler : public AZinxHandler {
public:
    virtual IZinxMsg *InternalHandle(IZinxMsg &input) {
        GET_REF2DATA(BytesMsg, output, input);
        ZinxKernel::Zinx_SendOut(output.szData, *stdoutChannel);
        return nullptr;
    }

    virtual AZinxHandler *GetNextHandler(IZinxMsg &handler) {
        return nullptr;
    }
} *echoHandler = new EchoHandler();

class ExitHandler : public AZinxHandler {
public:
    virtual IZinxMsg *InternalHandle(IZinxMsg &input){
        GET_REF2DATA(BytesMsg, output, input);
        if (output.szData == "exit") {
            ZinxKernel::Zinx_Exit();
            return NULL;
        }
        return new BytesMsg(output);
    }

    virtual AZinxHandler *GetNextHandler(IZinxMsg &handler){
        return echoHandler;
    }
} *exitHandler = new ExitHandler();

class StdinChannel : public Ichannel {
public:
    virtual bool Init() {
        return true;
    }

    virtual bool ReadFd(string &input) {
        cin >> input;
        return true;
    }

    virtual bool WriteFd(string &output) {
        return false;
    }

    virtual void Fini() {
        return ;
    }

    virtual int GetFd() {
        return STDIN_FILENO;
    }

    virtual string GetChannelInfo() {
        return "StdinChannel";
    }

    virtual AZinxHandler *GetInputNextStage(BytesMsg &input) {
        return exitHandler;
    }
} *stdinChannel = new StdinChannel();

int main(int argc, char *argv[]) {
    ZinxKernel::ZinxKernelInit();
    ZinxKernel::Zinx_Add_Channel(*stdinChannel);
    ZinxKernel::Zinx_Add_Channel(*stdoutChannel);
    ZinxKernel::Zinx_Run();
    ZinxKernel::ZinxKernelFini();

    return 0;
}