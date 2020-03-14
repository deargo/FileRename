#include "renameWindow.h"
#include "ui_renameWindow.h"

renameWindow::renameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::renameWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
}

renameWindow::~renameWindow()
{
    delete ui;
}

