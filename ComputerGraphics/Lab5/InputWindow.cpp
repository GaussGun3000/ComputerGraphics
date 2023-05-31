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
    PolyhedronSort::PolyhedronGeneratorSettings settings(
        ui.label_vMax->text().toUInt(),
        ui.spinBox_fMax->value(),
        ui.label_vMin->text().toUInt(),
        ui.spinBox_fMin->value(),
        ui.spinBox_polyCount->value()
    );

    mainWindow->saveInputData(settings);
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
    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
    auto settings = mainWindow->getGenSettings();
    ui.spinBox_polyCount->setValue(settings.polyhedronCount);
    ui.spinBox_fMin->setValue(settings.min_faces);
    ui.spinBox_fMax->setValue(settings.max_faces);
    ui.label_vMax->setText(QString::number(settings.max_vertices));
    ui.label_vMin->setText(QString::number(settings.min_vertices));
}

