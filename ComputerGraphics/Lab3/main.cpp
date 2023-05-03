#include "MainWindow.h"
#include <QtWidgets/QApplication>


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

#include <QDebug>
#include "polyhedron.h"

int main()
{
    Polyhedron poly = Polyhedron::generateRandomPolyhedron(10,);
    QVector3D c = poly.centroid();
    qDebug() << "Centroid: (" << c.x() << ", " << c.y() << ", " << c.z() << ")";
    return 0;
}
