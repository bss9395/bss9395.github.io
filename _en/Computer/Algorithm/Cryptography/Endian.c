/* Endian.c
Author: BSS9395
Update: 2020-01-13T12:24:00+08@China-Guangdong-Zhanjiang+08
Design: Endianness of Architecture
*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef  intptr_t  iptr;
typedef  unsigned  char   unch;
typedef  int8_t    in08;  typedef  int16_t   in16;  typedef  int32_t   in32;  typedef  int64_t   in64;
typedef  uint8_t   ui08;  typedef  uint16_t  ui16;  typedef  uint32_t  ui32;  typedef  uint64_t  ui64;

unch *Endian() {
    static unch *lsb = "Arithmetic: Left <<< Right";
    static unch *msb = "Notational: Left >>> Right";
    in32 data = 0x87654321;
    in08 *ptr = (in08 *)&data;
    if (ptr[0] == 0x21) {
        return lsb;
    }
    else if (ptr[0] == 0x87) {
        return msb;
    }
    return NULL;
}

iptr main(iptr argc, unch *argv[]) {
    unch *endian = Endian();
    fprintf(stdout, "%s\n", endian);

    return 0;
}
