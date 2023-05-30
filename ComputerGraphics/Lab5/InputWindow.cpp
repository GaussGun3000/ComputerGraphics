#include "InputWindow.h"
#include "MainWindow.h"
#include <QRandomGenerator>
#include <QVector3D>
#include <QtMath>

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
    uint32_t vMin = ui.label_vMin->text().toUInt();
    uint32_t vMax = ui.label_vMax->text().toUInt();
    uint32_t eMin = ui.spinBox_fMin->value();
    uint32_t eMax = ui.spinBox_fMax->value();

    mainWindow->saveInputData(polyhedronCount, vMin, vMax, eMin, eMax);
}

void InputWindow::eMaxSpinBoxValueChanged()
{
    if(ui.spinBox_fMax->value() == 2 || ui.spinBox_fMax->value() == 3)
        ui.label_vMax->setText("4");
    else
        ui.label_vMax->setText(QString::number(ui.spinBox_fMax->value()));
    ui.spinBox_fMin->setMaximum(ui.spinBox_fMax->value());
}

void InputWindow::eMinSpinBoxValueChanged()
{
    if (ui.spinBox_fMin->value() == 2 || ui.spinBox_fMin->value() == 3)
        ui.label_vMin->setText("4");
    else
        ui.label_vMin->setText(QString::number(ui.spinBox_fMin->value()));
    ui.spinBox_fMax->setMinimum(ui.spinBox_fMin->value());
}

void InputWindow::fillOldValues()
{

}

void InputWindow::randomButtonClicked()
{
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    
    mainWindow->generatePolyhedrons();
}
