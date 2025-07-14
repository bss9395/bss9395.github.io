#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int inet_aton(const char *cp, struct in_addr *inp);
in_addr_t inet_addr(const char *cp);
in_addr_t inet_network(const char *cp);
char *inet_ntoa(struct in_addr in);
struct in_addr inet_makeaddr(in_addr_t net, in_addr_t host);
in_addr_t inet_lnaof(struct in_addr in);
in_addr_t inet_netof(struct in_addr in);
#endif // 0

void func01() {
	struct in_addr net;
	inet_aton("192.168.50.150", &net);
	char *addr = inet_ntoa(net);
	printf("%#x\n", net.s_addr);
	printf("%s\n", addr);

	in_addr_t networkorder = inet_addr("192.168.50.150");
	in_addr_t hostorder = inet_network("192.168.50.150");
	printf("%#x\n", networkorder);
	printf("%#x\n", hostorder);
}

void func02() {
	struct in_addr net;
	inet_aton("192.168.50.150", &net);

	in_addr_t subnet_hostorder = inet_netof(net);
	in_addr_t host_hostorder = inet_lnaof(net);
	printf("%#x\n", subnet_hostorder);
	printf("%#x\n", host_hostorder);

	struct in_addr netaddr = inet_makeaddr(subnet_hostorder, host_hostorder);
	printf("%#x\n", netaddr.s_addr);
}

int main(int argc, char *argv[]) {
	func01();
	printf("--------------------\n");
	func02();

	return 0;
}

/* output:
0x9632a8c0
192.168.50.150
0x9632a8c0
0xc0a83296
--------------------
0xc0a832
0x96
0x9632a8c0
*/
