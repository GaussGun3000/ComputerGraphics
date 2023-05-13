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
    QPoint upperLeft = QPoint(ui.spinBox_x1->value(), ui.spinBox_y1->value());
    QPoint lowerRight = QPoint(ui.spinBox_x2->value(), ui.spinBox_y2->value());
    mainWindow->saveInputData(upperLeft, lowerRight);
}

void InputWindow::fillOldValues()
{
}

void InputWindow::randomButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    uint32_t segNumber = ui.spinBox_segNumber->value();
    uint32_t maxLength = ui.spinBox_maxLength->value();
    mainWindow->generateSegments(segNumber, maxLength);
}
