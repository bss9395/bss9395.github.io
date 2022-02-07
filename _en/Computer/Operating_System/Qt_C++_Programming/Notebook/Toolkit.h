/* Toolkit.h
Author: BSS9395
Update: 2022-02-08T00:24:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Toolkit_h
#define Toolkit_h

#define Header_h
#include "Common.h"
#include "System.h"

class Style {
public:
    static inline const QString _close_unsaved = R"(
        QWidget {
            border: 0px solid;
            image: url(":/images/custom_circle.png");
        }
        QWidget:hover {
            border: 0px solid;
            image: url(":/images/custom_close.png");
        }
    )";

    static inline const QString _close_saved = R"(
        QWidget {
            border: 0px solid;
            image: url(":/images/custom_close.png");
        }
    )";
};

#endif // Toolkit_h
