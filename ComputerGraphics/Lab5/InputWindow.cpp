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

void InputWindow::fMaxSpinBoxValueChanged()
{
    uint32_t fMax = ui.spinBox_fMax->value();
    if(fMax >= 2 && fMax <=4)
    {
        ui.label_vMin->setText("4");
        ui.label_vMax->setText("4");
    }
    else if (fMax == 5)
    {
        ui.label_vMin->setText("5");
        ui.label_vMax->setText("6");
    }
    else
    {
        ui.label_vMin->setText(QString::number(calcMinV(fMax)));
        ui.label_vMax->setText(QString::number(fMax));
    }
    ui.spinBox_fMin->setMaximum(fMax);
}

void InputWindow::fMinSpinBoxValueChanged()
{
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

uint32_t InputWindow::factorial(uint32_t n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

uint32_t InputWindow::calcMinV(uint32_t maxF)
{
    uint32_t m = 4; 

    while (true) {
        uint32_t numerator = factorial(m);
        uint32_t denominator = factorial(3) * factorial(m - 3);

        if (numerator >= (denominator * maxF))
            return m + 1;

        m++;  
    }
}

