/* Poco_DNS_resolve.cpp
Author: bss9395
Update: 2024-09-26T11:56:00+08@China-Beijing+08
*/

#include <iostream>
#include "Poco/Net/DNS.h"

static void _DNS_resolve(const std::string &host) {
	Poco::Net::HostEntry hostEntry(host.empty() ? Poco::Net::DNS::thisHost() : Poco::Net::DNS::resolve(host));
	std::cout << "hostEntry.name() = " << hostEntry.name() << std::endl;

	Poco::Net::HostEntry::AliasList aliasList(hostEntry.aliases());
	for (int i = 0; i < aliasList.size(); i += 1) {
		std::cout << "    aliasList[" << i << "] = " << aliasList[i] << std::endl;
	}

	Poco::Net::HostEntry::AddressList addressList(hostEntry.addresses());
	for (int i = 0; i < addressList.size(); i += 1) {
		std::cout << "    addressList[" << i << "] = " << addressList[i] << std::endl;
	}
}

int main(int argc, char *argv[]) {
	_DNS_resolve("");                                         // thisHost
	_DNS_resolve("baidu.com");                                // Domain
	_DNS_resolve("www.baidu.com");                            // SubDomain
	_DNS_resolve("192.168.119.61");                           // IPv4 Address
	_DNS_resolve("2408:8409:18b0:3c4b:4b3d:95bc:bd6e:8d1c");  // IPv6 Address
	_DNS_resolve("2408:8409:18b0:3c4b:ec3f:b255:1d57:7ddf");  // Temporary IPv6 Address
	_DNS_resolve("fe80::bc2a:4cd9:7442:b48b%8");              // Link-local IPv6 Address

	return 0;
}
