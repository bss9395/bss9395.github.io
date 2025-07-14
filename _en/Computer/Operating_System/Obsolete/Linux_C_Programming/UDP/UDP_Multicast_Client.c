/* UDP_Multicast_Client.c
Author: BSS9395
Update: 2023-10-04T16:50:00+08@China-Guangdong-Zhanjiang+08
*/

#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <net/if.h>

static const int   _multicast_port  = 9000;
static const char *_multicast_addr = "239.0.0.2";

int main(int argc, char *argv[]) {
    int confd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in local_addr;
	bzero(&local_addr, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	local_addr.sin_port = htons(_multicast_port);
	bind(confd, (struct sockaddr *)&local_addr, sizeof(local_addr));

	struct ip_mreqn group;
    group.imr_multiaddr.s_addr = inet_addr(_multicast_addr);
    group.imr_address.s_addr = inet_addr("0.0.0.0");
	group.imr_ifindex = if_nametoindex("eth0");
	setsockopt(confd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &group, sizeof(group));

    char buffer[1024];
	while (1) {
		int len = recvfrom(confd, buffer, sizeof(buffer), 0, NULL, 0);
        buffer[len] = '\0';
		fprintf(stdout, "%s\n", buffer);
	}
	close(confd);
	return 0;
}
