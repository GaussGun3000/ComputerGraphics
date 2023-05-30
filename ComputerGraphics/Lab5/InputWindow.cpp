#include "InputWindow.h"
#include "MainWindow.h"
#include <QRandomGenerator>
#include <QVector3D>

InputWindow::InputWindow(QWidget* parent):
QDialog(parent)
{
    ui.setupUi(this);
    fillOldValues();
}

void InputWindow::saveButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    uint32_t polyhedronCount = ui.spinBox_polyCount->value();
    uint32_t vMin = ui.spinBox_vMin->value();
    uint32_t vMax = ui.spinBox_vMax->value();
    uint32_t eMin = ui.spinBox_eMin->value();
    uint32_t eMax = ui.spinBox_eMax->value();

    mainWindow->saveInputData(polyhedronCount, vMin, vMax, eMin, eMax);
}

void InputWindow::fillOldValues()
{

}

void InputWindow::randomButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    
    mainWindow->generatePolyhedrons();
}
