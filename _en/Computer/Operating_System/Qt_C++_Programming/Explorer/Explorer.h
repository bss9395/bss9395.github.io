/* Explorer.h
Author: BSS9395
Update: 2022-01-15T01:30:00+08@China-Guangdong-Shenzhen+08
Design: File Explorer
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Explorer_h
#define Explorer_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Explorer.h"

class File_System : public QMainWindow {
    Q_OBJECT

public:
    Ui::File_System *_ui = nullptr;
    QTimer timer = QTimer(this);
    QFileSystemModel _model = QFileSystemModel(this);
    std::list<QModelIndex> _history = std::list<QModelIndex>();
    std::list<QModelIndex>::iterator _index = std::list<QModelIndex>::iterator();

public:
    File_System(QWidget *parent = nullptr);
    ~File_System();

public:
    void Enable_Direction(iptr milli = 50);
};
#endif // Explorer_h
