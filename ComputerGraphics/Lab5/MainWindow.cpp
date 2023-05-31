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

void MainWindow::saveInputData(uint32_t& polyhedronCount, uint32_t& vMin, uint32_t& vMax, uint32_t& eMin, uint32_t& eMax)
{
    ui.statusBar->showMessage("Polyhedron parameters were saved. Press update to render with new values");
}

void MainWindow::generatePolyhedrons()
{
}

void MainWindow::updateButtonClicked()
{
    ui.renderArea->updateScene();
    ui.statusBar->showMessage("Updated");
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

