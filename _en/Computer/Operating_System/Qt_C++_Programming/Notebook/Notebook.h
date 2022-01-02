#ifndef Notebook_h
#define Notebook_h

#include "Common.h"

class MW_Notebook : public QMainWindow{
    Q_OBJECT

private:
    Ui::MW_Notebook *ui;

public:
    MW_Notebook(QWidget *parent = nullptr);
    ~MW_Notebook();
};
#endif // Notebook_h
