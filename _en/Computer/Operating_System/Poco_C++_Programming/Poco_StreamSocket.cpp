/* Poco_ServerSocket.cpp
Author: bss9395
Update: 2024-09-27T01:10:00+08@China-Beijing+08
*/

#include "Poco/ConsoleChannel.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/LocalDateTime.h"
#include "Poco/Logger.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/StreamCopier.h"
#include <QApplication>
#include <QFile>
#include <QtConcurrent>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

namespace Config {
	inline static Poco::Logger& _logger = []() -> Poco::Logger& {
		Poco::AutoPtr<Poco::ConsoleChannel> consoleChannel(new Poco::ConsoleChannel());
		Poco::Logger::root().setChannel(consoleChannel);
		Poco::Logger::root().setLevel(Poco::Message::PRIO_TRACE);
		return Poco::Logger::root();
	}();
#define _PocoDebug(...)  Config::_logger.debug(__VA_ARGS__)	
};

// Poco::SocketStream功能不完善
void _Poco_SocketStream() {
	_PocoDebug("[%s] enter", std::string(__FUNCTION__));
	try {
		Poco::Net::SocketAddress address("www.baidu.com", 80);
		Poco::Net::StreamSocket tcp_client(address);
		Poco::Net::SocketStream tcp_stream(tcp_client);

        tcp_stream << ""
			"GET / HTTP/1.1\r\n"
			"Host: www.baidu.com\r\n"
			"\r\n"
			"";
		tcp_stream.flush();

		// std::fstream file("./baidu.html", std::fstream::out | std::fstream::trunc | std::fstream::binary);
		// Poco::StreamCopier::copyStream(tcp_stream, file);
        Poco::StreamCopier::copyStream(tcp_stream, std::cout);  
	} catch (const Poco::Exception &exception) {
		std::cerr << exception.displayText() << std::endl;
	}

	_PocoDebug("[%s] leave", std::string(__FUNCTION__));
}

void _Poco_ServerSocket() {
	_PocoDebug("[%s] enter", std::string("_Poco_ServerSocket"));
	try {
		Poco::Net::ServerSocket tcp_server(9395);  // bind + listen

		while (true) {
			Poco::Net::StreamSocket tcp_client(tcp_server.acceptConnection());
			_PocoDebug("[%s] %s", std::string("_Poco_ServerSocket"), std::string("Poco::Net::StreamSocket tcp_client(tcp_server.acceptConnection());"));

			auto _Connected = [tcp_client]() mutable -> void {
				_PocoDebug("[%s] %s", std::string("_Poco_ServerSocket"), std::string("static auto _Connected = [tcp_client]() mutable -> void {"));
				_PocoDebug("[%s] %s", std::string("_Poco_ServerSocket"), tcp_client.peerAddress().toString()); 
				
				std::string content(""
					"HTTP/1.0 200 OK\r\n"
					"Content-Type: text/html\r\n"
					"\r\n"
					"<html>\n"
					"    <head>\n"
					"        <title>Web Server</title>\n"
					"    </head>\n"
					"    <body>\n"
					"        <h1>Hello, world!</h1>\n"
					"    </body>\n"
					"</html>\n"
				);
				tcp_client.sendBytes(content.data(), (long)content.size());
			};
			std::thread(_Connected).detach();

			auto _ReadyRead = [tcp_client]() mutable -> void {
				_PocoDebug("[%s] %s", std::string("_Poco_ServerSocket"), std::string("static auto _ReadyRead = [tcp_client]() mutable -> void {"));
				
				for (std::string buffer = ""; true; ) {
					if (0 < tcp_client.available()) {
						buffer.resize(tcp_client.available());
						long length = tcp_client.receiveBytes(buffer.data(), tcp_client.available());
						_PocoDebug("[%s] %s", std::string("_Poco_ServerSocket"), buffer);
					}
				}
			};
			std::thread(_ReadyRead).detach();
		}
	} catch (const Poco::Exception& exception) {
		std::cerr << exception.displayText() << std::endl;
	}
}

void _Poco_StreamSocket() {
	_PocoDebug("[%s] enter", std::string("_Poco_StreamSocket"));
	try {
		Poco::Net::StreamSocket tcp_client(Poco::Net::SocketAddress("127.0.0.1", 9395));

		auto _Connected = [tcp_client]() mutable -> void {
			_PocoDebug("[%s] %s", std::string("_Poco_StreamSocket"), std::string("static auto _Connected = [tcp_client]() mutable -> void {"));
			_PocoDebug("[%s] %s", std::string("_Poco_StreamSocket"), tcp_client.peerAddress().toString());

			std::string timestamp(Poco::DateTimeFormatter::format(Poco::LocalDateTime(), Poco::DateTimeFormat::ISO8601_FORMAT));
			tcp_client.sendBytes(timestamp.data(), (long)timestamp.size());
		};
		std::thread(_Connected).detach();

		auto _ReadyRead = [tcp_client]() mutable -> void {
			_PocoDebug("[%s] %s", std::string("_Poco_StreamSocket"), std::string("static auto _ReadyRead = [tcp_client]() mutable -> void {"));
			
			for (std::string buffer = ""; true; ) {
				if (0 < tcp_client.available()) {
					buffer.resize(tcp_client.available());
					long length = tcp_client.receiveBytes((char *)buffer.data(), (long)buffer.size());
					_PocoDebug("[%s] %s", std::string("_Poco_StreamSocket"), buffer);
				}
			}
		};
		std::thread(_ReadyRead).detach();
	} catch (const Poco::Exception &exception) {
		std::cerr << exception.displayText() << std::endl;
	}
}

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	// QtConcurrent::run(_Poco_SocketStream);
	QtConcurrent::run(_Poco_ServerSocket);
	QtConcurrent::run(_Poco_StreamSocket);

	return a.exec();
}
