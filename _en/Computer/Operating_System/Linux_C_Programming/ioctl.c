#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if.h>
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#if 0
int ioctl(int fd, unsigned long request, ...);
#endif

const int MAX_INTERFACE = 32;

void get_interface_flags(unsigned if_flags) {
	printf("interface flags: \n");
	if (if_flags & IFF_UP) {
		printf("     Interface is running. \n");
	}
	if (if_flags & IFF_BROADCAST) {
		printf("     Valid broadcast address set. \n");
	}
	if (if_flags & IFF_DEBUG) {
		printf("     Internal debugging flag. \n");
	}
	if (if_flags & IFF_LOOPBACK) {
		printf("     Interface is a loopback interface. \n");
	}
	if (if_flags & IFF_POINTOPOINT) {
		printf("     Interface is a point-to-point link. \n");
	}
	if (if_flags & IFF_RUNNING) {
		printf("     Resources allocated. \n");
	}
	if (if_flags & IFF_NOARP) {
		printf("     No arp protocol, L2 destination address not set. \n");
	}
	if (if_flags & IFF_PROMISC) {
		printf("     Interface is in promiscuous mode. \n");
	}
	if (if_flags & IFF_NOTRAILERS) {
		printf("     Avoid use of trailers. \n");
	}
	if (if_flags & IFF_ALLMULTI) {
		printf("     Receive all multicast packets. \n");
	}
	if (if_flags & IFF_MASTER) {
		printf("     Master of a load balancing bundle. \n");
	}
	if (if_flags & IFF_SLAVE) {
		printf("     Slave of a load balancing bundle. \n");
	}
	if (if_flags & IFF_MULTICAST) {
		printf("     Supports multicast \n");
	}
	if (if_flags & IFF_PORTSEL) {
		printf("     Is able to select media type via ifmap. \n");
	}
	if (if_flags & IFF_AUTOMEDIA) {
		printf("     Auto media selection active. \n");
	}
	if (if_flags & IFF_DYNAMIC) {
		printf("     The addresses are lost when the interface goes down. \n");
	}
	// if (if_flags & IFF_LOWER_UP) {
	// 	printf("     Driver signals L1 up (since Linux 2.6.17) \n");
	// }
	// if (if_flags & IFF_DORMANT) {
	// 	printf("     Driver signals dormant (since Linux 2.6.17) \n");
	// }
	// if (if_flags & IFF_ECHO) {
	// 	printf("     Echo sent packets (since Linux 2.6.25) \n");
	// }
}

void set_interface_flags(int fd, struct ifreq *interface) {
	// interface.ifr_flags |= IFF_PROMISC;  // set
	// interface.ifr_flags &= ~IFF_PROMISC; // unset
	int err = ioctl(fd, SIOCSIFFLAGS, (char *)interface);
	assert(0 <= err);
}

int main(int argc, char *argv[]) {
	int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	assert(0 <= sock_fd);

	struct ifreq  interfaces[MAX_INTERFACE];
	struct ifconf config;
	config.ifc_len = sizeof(interfaces);
	config.ifc_buf = (char *)interfaces;
	int err = ioctl(sock_fd, SIOCGIFCONF, (char *)&config);
	assert(0 <= err);

	int count = config.ifc_len / sizeof(struct ifreq);
	printf("%d interfaces\n", count);

	for(int cnt = 0; cnt < count; ++cnt) {
		printf("----------------------------------------\n");

		/* get interface name */
		printf("interface name: \n");
		printf("     %s\n", interfaces[cnt].ifr_name);

		/* set interface flags, interface may not support */
		struct ifreq interface = {'\0'};
		strncpy(interface.ifr_name, interfaces[cnt].ifr_name, sizeof(interfaces[cnt].ifr_name));
		err = ioctl(sock_fd, SIOCGIFFLAGS, (char *)&interface);
		assert(0 <= err);
		//set_interface_flags(sock_fd, &interface);

		/* get interface flags */
		err = ioctl(sock_fd, SIOCGIFFLAGS, (char *)&(interfaces[cnt]));
		assert(0 <= err);
		get_interface_flags(interfaces[cnt].ifr_flags);

		/* get interface IP address */
		int err = ioctl(sock_fd, SIOCGIFADDR, (char *)&(interfaces[cnt]));
		assert(0 <= err);
		printf("interface IP address: \n");
		printf("     %s\n", inet_ntoa(((struct sockaddr_in *)(&interfaces[cnt].ifr_addr))->sin_addr));

		/* get interface MAC address */
		err = ioctl(sock_fd, SIOCGIFHWADDR, (char *)&(interfaces[cnt]));
		assert(0 <= err);
		printf("interface MAC address: \n");
		printf("     %02x:%02x:%02x:%02x:%02x:%02x\n",
			(unsigned char)interfaces[cnt].ifr_hwaddr.sa_data[0],
			(unsigned char)interfaces[cnt].ifr_hwaddr.sa_data[1],
			(unsigned char)interfaces[cnt].ifr_hwaddr.sa_data[2],
			(unsigned char)interfaces[cnt].ifr_hwaddr.sa_data[3],
			(unsigned char)interfaces[cnt].ifr_hwaddr.sa_data[4],
			(unsigned char)interfaces[cnt].ifr_hwaddr.sa_data[5]);
	}

	close(sock_fd);
	return 0;
}