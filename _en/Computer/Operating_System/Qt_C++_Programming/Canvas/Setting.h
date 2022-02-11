/* Setting.h
Author: BSS9395
Update: 2022-02-12T02:12:00+08@China-Guangdong-Shenzhen+08
Design: Canvas
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Setting_h
#define Setting_h

#define Header_h
#include "Common.h"

class Setting {
public:
    static inline QString _Organization = "BSS9395";
    static inline QString _Software = "画布";
    static inline QCryptographicHash::Algorithm _Crypto = QCryptographicHash::Sha3_256;
    static inline QString _Username = "bss";
    static inline QString _Password = "pass";
};

#endif // Setting_h
