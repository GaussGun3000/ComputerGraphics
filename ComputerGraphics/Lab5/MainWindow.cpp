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

void MainWindow::saveInputData(PolyhedronSort::PolyhedronGeneratorSettings& settings)
{
    ui.renderArea->setAlgorithmSettings(settings);
    ui.statusBar->showMessage("Polyhedron parameters were saved. Press update to render with new values");
}

void MainWindow::generatePolyhedrons()
{
}

PolyhedronSort::PolyhedronGeneratorSettings MainWindow::getGenSettings()
{
    return ui.renderArea->getAlgorithmSettings();
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

