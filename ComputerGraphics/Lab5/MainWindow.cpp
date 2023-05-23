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

void MainWindow::saveInputData(QPoint& upperLeft, QPoint& lowerRight)
{
    ui.statusBar->showMessage("New reactangle was saved. Press update to render with new values");
}

void MainWindow::generateSegments(uint32_t lineCount, uint32_t maxlen)
{

}



void MainWindow::updateButtonClicked()
{

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

