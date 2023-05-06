#include "InputWindow.h"
#include "MainWindow.h"
#include <QRandomGenerator>
#include <QVector3D>

InputWindow::InputWindow(QWidget* parent):
QDialog(parent)
{
    ui.setupUi(this);
}

void InputWindow::saveButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    QVector<QVector3D> points;
    
    points.reserve(4);



    //extract the points from spin boxes (can use lab2 as example)

    mainWindow->saveInputData(points);
}

void InputWindow::randomButtonClicked()
{
    double x1 = (rand() % 10100) * 0.01;
    double y1 = (rand() % 10100) * 0.01;
    double z1 = (rand() % 10100) * 0.01;

    double x2 = (rand() % 10100) * 0.01;
    double y2 = (rand() % 10100) * 0.01;
    double z2 = (rand() % 10100) * 0.01;

    double x3 = (rand() % 10100) * 0.01;
    double y3 = (rand() % 10100) * 0.01;
    double z3 = (rand() % 10100) * 0.01;
    
    double x4 = (rand() % 10100) * 0.01;
    double y4 = (rand() % 10100) * 0.01;
    double z4 = (rand() % 10100) * 0.01;

    ui.spinBox_x1->setValue(x1);
    ui.spinBox_y1->setValue(y1);
    ui.spinBox_z1->setValue(z1);
    ui.spinBox_x2->setValue(x2);
    ui.spinBox_y2->setValue(y2);
    ui.spinBox_z2->setValue(z2);
    ui.spinBox_x3->setValue(x3);
    ui.spinBox_y3->setValue(y3);
    ui.spinBox_z3->setValue(z3);
    ui.spinBox_x4->setValue(x4);
    ui.spinBox_y4->setValue(y4);
    ui.spinBox_z4->setValue(z4);
}
