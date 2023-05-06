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

}
