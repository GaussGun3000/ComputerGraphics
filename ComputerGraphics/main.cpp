#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setFont(QFont("Arial", 11));
    MainWindow w;
    w.show();
    return a.exec();
}
