#include "renameWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    renameWindow w;
    w.show();
    return a.exec();
}
