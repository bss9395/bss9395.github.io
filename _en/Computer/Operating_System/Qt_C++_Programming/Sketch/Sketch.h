/* Common.h
Author: BSS9395
Update: 2022-01-11T21:16:00+08@China-Guangdong-Shenzhen+08
Design: Sketch
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Sketch_h
#define Sketch_h

#include "Common.h"

class Sketch : public QMainWindow {
    Q_OBJECT

public:
    static inline iptr _Folder = 1000;
    static inline iptr _File = 1001;
    static inline iptr _Path = 0;
    static inline iptr _Type = 1;

public:
    Ui::Sketch *_ui = nullptr;

public:
    Sketch(QWidget *parent = nullptr);
    ~Sketch();

public:
    QTreeWidgetItem *Traverse(QTreeWidgetItem *tree, const QChar *directory, bool &hitted);
};
#endif // Sketch_h
