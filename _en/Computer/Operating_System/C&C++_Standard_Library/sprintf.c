/* sprintf.c
Author: BSS9395
Update: 2021-09-05T17:13:00+08@China-Guangdong-Zhanjiang+08
Design: sprintf
*/

/*
#include <stdio.h>
int sprintf ( char * str, const char * format, ... );
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool IP4_to_Number(unsigned *number, char *ip4) {
    unsigned ip_number[4];
    if (4 != sscanf(ip4, "%u.%u.%u.%u", &ip_number[3], &ip_number[2], &ip_number[1], &ip_number[0])) {
        return false;
    }

    if (!(ip_number[3] <= 255 && ip_number[2] <= 255 && ip_number[1] <= 255 && ip_number[0] <= 255)) {
        return false;
    }

    (*number) = (ip_number[3] << 24) | (ip_number[2] << 16) | (ip_number[1] << 8) | (ip_number[0] << 0);
    return true;
}

bool Number_to_IP4(char *ip4, unsigned number) {
    unsigned ip_number[4];
    ip_number[3] = (number >> 24) & 0xFF;
    ip_number[2] = (number >> 16) & 0xFF;
    ip_number[1] = (number >> 8) & 0xFF;
    ip_number[0] = (number >> 0) & 0xFF;

    if (!(ip_number[3] <= 255 && ip_number[2] <= 255 && ip_number[1] <= 255 && ip_number[0] <= 255)) {
        return false;
    }

    sprintf(ip4, "%u.%u.%u.%u", ip_number[3], ip_number[2], ip_number[1], ip_number[0]);
    return true;
}

unsigned SubNet(unsigned ip4, unsigned mask) {
    return (ip4 & mask);
}

int main(int argc, char *argv[]) {
    //char *ip4 = (char *)"234.237.37.104";
    //unsigned number = 0;
    //IP4_to_Number(&number, ip4);
    //fprintf(stdout, "%u""\n", number);

    ////////////////////////////////////

    //char ip4[1024];
    //unsigned number = 167969729;
    //Number_to_IP4(ip4, number);
    //fprintf(stdout, "%s""\n", ip4);

    ////////////////////////////////////

    char *mask = (char *)"254.255.0.0";
    char *ip4_1 = (char *)"85.122.52.249";
    char *ip4_2 = (char *)"10.57.28.117";
    unsigned mask_number = 0;
    unsigned ip4_1_number = 0;
    unsigned ip4_2_number = 0;

    /* Example
    (unsigned)mask     = 0b11111111111111110000000000000000  // valid mask
    (unsigned)mask - 1 = 0b11111111111111101111111111111111
    mask | (mask - 1)  = 0b11111111111111111111111111111111
    ------------------------------------
    (unsigned)mask     = 0b11110000000011110000000000000000  // invalid mask
    (unsigned)mask - 1 = 0b11110000000011101111111111111111
    mask | (mask - 1)  = 0b11110000000011111111111111111111
    ------------------------------------
    (unsigned)mask     = 0b00000000000000000000000000000000  // invalid mask
    (unsigned)mask - 1 = 0b11111111111111111111111111111111
    mask | (mask - 1)  = 0b11111111111111111111111111111111
    ------------------------------------
    (unsigned)mask     = 0b11111111111111111111111111111111  // invalid mask
    (unsigned)mask - 1 = 0b11111111111111111111111111111110
    mask | (mask - 1)  = 0b11111111111111111111111111111111
    */

    /* Example
    (unsigned)mask                                      = 0b11111111111111110000000000000000  // valid mask
    -(signed)mask                                       = 0b00000000000000010000000000000000
    mask_number & -(signed)mask_number)                 = 0b00000000000000010000000000000000
    mask_number + (mask_number & -(signed)mask_number)) = 0b00000000000000000000000000000000
    ------------------------------------
    (unsigned)mask                                      = 0b11110000000011110000000000000000  // invalid mask
    -(signed)mask                                       = 0b00001111111100010000000000000000
    mask_number & -(signed)mask_number)                 = 0b00000000000000010000000000000000
    mask_number + (mask_number & -(signed)mask_number)) = 0b11110000000100000000000000000000
    ------------------------------------
    (unsigned)mask                                      = 0b00000000000000000000000000000000  // invalid mask
    -(signed)mask                                       = 0b00000000000000000000000000000000
    mask_number & -(signed)mask_number)                 = 0b00000000000000000000000000000000
    mask_number + (mask_number & -(signed)mask_number)) = 0b00000000000000000000000000000000
    ------------------------------------
    (unsigned)mask                                      = 0b11111111111111111111111111111111  // invalid mask
    -(signed)mask                                       = 0b00000000000000000000000000000001
    mask_number & -(signed)mask_number)                 = 0b00000000000000000000000000000001
    mask_number + (mask_number & -(signed)mask_number)) = 0b00000000000000000000000000000000
    */

    //if (IP4_to_Number(&mask_number, mask) && (0 == mask_number + (mask_number & -(signed)mask_number)) && 0 != mask_number && 0 != ~mask_number ) {
    if (IP4_to_Number(&mask_number, mask) && (0xFFFFFFFF == mask_number | (mask_number - 1)) && 0 != mask_number && 0 != ~mask_number) {
        if (IP4_to_Number(&ip4_1_number, ip4_1) && IP4_to_Number(&ip4_2_number, ip4_2)) {
            if (SubNet(ip4_1_number, mask_number) == SubNet(ip4_2_number, mask_number)) {
                fprintf(stdout, "ip4_1 and ip4_2 are under the same subnet.""\n");
            }
            else {
                fprintf(stdout, "ip4_1 and ip4_2 are not under the same subnet.""\n");
            }
        }
        else {
            fprintf(stdout, "wrong ip4 address format.""\n");
        }
    }
    else {
        fprintf(stdout, "wrong ip4 mask format.""\n");
    }

    return 0;
}
