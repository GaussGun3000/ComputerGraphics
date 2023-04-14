#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{}

void MainWindow::updateButtonClicked()
{

}


void MainWindow::resizeEvent(QResizeEvent* event)
{
    ui.renderArea->update();
}

