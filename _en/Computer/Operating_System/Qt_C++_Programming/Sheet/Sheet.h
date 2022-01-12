#ifndef Sheet_h
#define Sheet_h

#include "Common.h"

class Sheet : public QMainWindow {
    Q_OBJECT

public:
    Ui::Sheet *_ui = nullptr;

public:
    Sheet(QWidget *parent = nullptr);
    ~Sheet();
};

#endif // Sheet_h
