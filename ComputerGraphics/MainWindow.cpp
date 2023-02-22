#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{}

void MainWindow::updateButtonClicked()
{

    bool okx, oky;

    QString x = ui.xTextInput->toPlainText();
    QString y = ui.yTextInput->toPlainText();
    int intx = x.toInt(&okx);
    int inty = y.toInt(&oky);
    ui.renderArea->updateReferencePoint(intx, inty);

    if (!(okx && oky)) 
        ui.statusBar->showMessage("data entered incorrectly");
    else 
        ui.statusBar->showMessage("point is update");
}
