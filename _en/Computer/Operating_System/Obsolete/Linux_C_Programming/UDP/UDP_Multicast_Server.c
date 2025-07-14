/* UDP_Multicast_Server.c
Author: BSS9395
Update: 2023-10-04T16:50:00+08@China-Guangdong-Zhanjiang+08
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdbool.h>

static const int   _multicast_port = 9000;
static const char *_multicast_addr = "239.0.0.2";

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	// struct sockaddr_in local_addr;
	// bzero(&local_addr, sizeof(local_addr));
	// local_addr.sin_family = AF_INET; 
	// local_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	// local_addr.sin_port = htons(_multicast_port);
	// bind(sockfd, (struct sockaddr *)&local_addr, sizeof(local_addr));

	// struct ip_mreqn group;
	// group.imr_multiaddr.s_addr = inet_addr(_multicast_addr);
	// group.imr_address.s_addr = inet_addr("0.0.0.0");
	// group.imr_ifindex = if_nametoindex("eth0");
	// setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_IF, &group, sizeof(group));

	struct sockaddr_in addr_multicast;
	bzero(&addr_multicast, sizeof(addr_multicast));
	addr_multicast.sin_family = AF_INET; 
	addr_multicast.sin_addr.s_addr = inet_addr(_multicast_addr);
	addr_multicast.sin_port = htons(_multicast_port);

	char buf[1024] = "hello, world!";
	while (true) {
		sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr_multicast, sizeof(addr_multicast));
		sleep(1);
	}
	close(sockfd);
	return 0;
}
