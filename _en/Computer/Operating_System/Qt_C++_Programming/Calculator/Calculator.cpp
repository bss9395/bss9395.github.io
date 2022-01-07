#include "Common.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);
}

Calculator::~Calculator() {
    delete ui;
}
