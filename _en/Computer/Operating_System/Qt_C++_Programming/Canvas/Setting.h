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
#include "System.h"

class Setting {
public:
    static inline const QString _Organization = "BSS9395";
    static inline const QString _Software = "画布";
    static inline const QCryptographicHash::Algorithm _Crypto = QCryptographicHash::Sha3_256;
    static inline const QString _Username = "bss";
    static inline const QString _Password = "pass";
    static inline const iptr _Tried = 3;
};

#endif // Setting_h
