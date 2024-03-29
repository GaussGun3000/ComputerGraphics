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
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    auto& cohSuthPtr = mainWindow->getCohenSutherland();
    if (!cohSuthPtr.isNull())
    {
        ui.spinBox_x1->setValue(cohSuthPtr->getRectangle().topRight().x());
        ui.spinBox_y1->setValue(cohSuthPtr->getRectangle().topRight().y());
        ui.spinBox_x2->setValue(cohSuthPtr->getRectangle().bottomLeft().x());
        ui.spinBox_y2->setValue(cohSuthPtr->getRectangle().bottomLeft().y());
        ui.spinBox_segNumber->setValue(cohSuthPtr->getSegmentGeneratorParams()[0]);
        ui.spinBox_maxLength->setValue(cohSuthPtr->getSegmentGeneratorParams()[1]);
    }
}

void InputWindow::randomButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    uint32_t segNumber = ui.spinBox_segNumber->value();
    uint32_t maxLength = ui.spinBox_maxLength->value();
    mainWindow->generateSegments(segNumber, maxLength);
}
