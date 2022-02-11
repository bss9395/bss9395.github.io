/* Toolkit.h
Author: BSS9395
Update: 2022-02-10T00:27:00+08@China-Guangdong-Zhanjiang+08
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
    static inline const QString _Close_Unsaved = R"(
        QWidget {
            border: 0px solid;
            image: url(":/images/custom_circle.png");
        }
        QWidget:hover {
            border: 0px solid;
            image: url(":/images/custom_close.png");
        }
    )";

    static inline const QString _Close_Saved = R"(
        QWidget {
            border: 0px solid;
            image: url(":/images/custom_close.png");
        }
    )";

    static inline const QString _Light_Background = R"(
        QTextEdit {
            background-color: rgba(255, 255, 255, 1.0);
        }
        QTabBar::Tab:selected {
            background-color: rgba(255, 255, 255, 1.0);
        }
    )";

    static inline const QString _Gray_Background = R"(
        QTextEdit {
            background-color: rgba(127, 127, 127, 1.0);
        }
        QTabBar::Tab:selected {
            background-color: rgba(127, 127, 127, 1.0);
        }
    )";

    static inline const QString _Dark_Background = R"(
        QTextEdit {
            background-color: rgba(0, 0, 0, 1.0);
        }
        QTabBar::Tab:selected {
            background-color: rgba(0, 0, 0, 1.0);
        }
    )";
};

#endif // Toolkit_h
