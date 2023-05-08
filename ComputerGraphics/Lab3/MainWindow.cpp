#include "MainWindow.h"
#include "InputWindow.h"
#include <qvector3d.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{}

void MainWindow::saveInputData(QVector<QVector3D>& points)
{
    ui.renderArea->surface->setCornerPoints(points);
    ui.statusBar->showMessage("Corner points saved. Press update to render new surface");
}

QVector<QVector3D> MainWindow::getSurfaseData()
{
    return ui.renderArea->surface->cornerPoints();
}


void MainWindow::updateButtonClicked()
{
    float angleX = ui.spinBox_angleX->value(); 
    float angleY = ui.spinBox_angleY->value();
    ui.renderArea->updateSurface(angleX, angleY);
    ui.statusBar->showMessage("Surface updated");
}


void MainWindow::inputButtonClicked()
{
    InputWindow inputWindow(this);
    inputWindow.exec();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    ui.renderArea->update();
}

