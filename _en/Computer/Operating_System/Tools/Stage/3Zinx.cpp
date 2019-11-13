#include "zinx.h"
#include "ZinxTCP.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class StdoutChannel: public Ichannel {
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
			return NULL;
		}
} *stdoutChannel = new StdoutChannel();

class EchoHandler:public AZinxHandler {
	public:
		virtual IZinxMsg *InternalHandle(IZinxMsg &input) {
			GET_REF2DATA(BytesMsg, output, input);
			Ichannel *channel;
			if(output.szInfo == "StdinChannel") {
				channel = ZinxKernel::Zinx_GetChannel_ByInfo("StdoutChannel");
			}
			else {
				channel = ZinxKernel::Zinx_GetChannel_ByInfo(output.szInfo);
			}

			if (NULL != channel) {
				ZinxKernel::Zinx_SendOut(output.szData, *channel);
			}
			return NULL;
		}

		virtual AZinxHandler *GetNextHandler(IZinxMsg &msg) {
			return NULL;
		}
} *echoHandler = new EchoHandler();


class ExitHandler:public AZinxHandler {
	public:
		virtual IZinxMsg *InternalHandle(IZinxMsg &input) {
			GET_REF2DATA(BytesMsg, output, input);
			if (output.szData == "exit") {
				ZinxKernel::Zinx_Exit();
				return NULL;
			}
			return new BytesMsg(output);
		}
		virtual AZinxHandler *GetNextHandler(IZinxMsg &msg) {
			return echoHandler;
		}
} *exitHandler = new ExitHandler();

class CommandHandler:public AZinxHandler {
	public:
		virtual IZinxMsg *InternalHandle(IZinxMsg &input) {
			GET_REF2DATA(BytesMsg, output, input);
			if (output.szData == "close") {
				ZinxKernel::Zinx_Del_Channel(*stdoutChannel);
				return NULL;
			}
			else if (output.szData == "open") {
				ZinxKernel::Zinx_Add_Channel(*stdoutChannel);
				return NULL;
			}
			return new BytesMsg(output);
		}
		virtual AZinxHandler *GetNextHandler(IZinxMsg &msg) {
			GET_REF2DATA(BytesMsg, output, msg);
			if (output.szData == "exit") {
				return exitHandler;
			}
			else {
				return echoHandler;
			}
		}
} *commandHandler = new CommandHandler();

class StdinChannel:public Ichannel {
	public:
		virtual bool Init() {
			return true;
		}

		virtual bool ReadFd(string &input) {
			cin>>input;
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
			return commandHandler;
		}
} *stdinChannel = new StdinChannel();

class TCPData: public ZinxTcpData {
	public:
		TCPData(int fd)
			:ZinxTcpData(fd) {

			}
		virtual AZinxHandler *GetInputNextStage(BytesMsg &input) {
			return commandHandler;
		}
};

class TCPFactory: public IZinxTcpConnFact {
	virtual ZinxTcpData *CreateTcpDataChannel(int fd) {
		return new TCPData(fd);
	}
};

int main(int argc, char *argv[]) {
	ZinxKernel::ZinxKernelInit();
	ZinxKernel::Zinx_Add_Channel(*stdinChannel);
	ZinxKernel::Zinx_Add_Channel(*stdoutChannel);
	auto channel = new ZinxTCPListen(7766, new TCPFactory());
	ZinxKernel::Zinx_Add_Channel(*channel);
	ZinxKernel::Zinx_Run();
	ZinxKernel::ZinxKernelFini();
	return 0;
}
