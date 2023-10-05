/* ntohl.c
Author: BSS9395
Update: 2023-09-26T18:00:00+08@China-Guangdong-Zhanjiang+08
Design: Linux Standard Library: ntohl
*/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <arpa/inet.h>

/*
#include <arpa/inet.h>
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
*/

int main(void) {
    unsigned int a = 0x12345678;
    unsigned int ret = 0;

    printf("sizeof(long): %ld\n", sizeof(long));

    ret = htonl(a);
    printf("ret = %#X\n", ret);

    ret = ntohl(a);
    printf("ret = %#X\n", ret);
    return 0;
}
