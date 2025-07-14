#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <arpa/inet.h>

/*
#include <arpa/inet.h>
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
*/

int main(int argc, char *argv[]) {
    char buffer[4]; 
    char ipv4[16];

    inet_pton(AF_INET, "192.168.19.78", buffer);
    printf("%u %u %u %u\n", buffer[0] & 0xff, buffer[1] & 0xff, buffer[2] & 0xff, buffer[3] & 0xff);

    memset(ipv4, 0, sizeof(ipv4));
    inet_ntop(AF_INET, buffer, ipv4, 16);
    printf("ip: %s\n", ipv4);

    return 0;
}
