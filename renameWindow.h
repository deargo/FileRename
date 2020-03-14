#pragma once

// Coding: UTF-8(BOM)
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class renameWindow; }
QT_END_NAMESPACE

class renameWindow : public QMainWindow
{
    Q_OBJECT

public:
    renameWindow(QWidget *parent = nullptr);
    ~renameWindow();

private:
    Ui::renameWindow *ui;
};

