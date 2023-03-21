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

    bool okx, oky, okAng;

    QString x = ui.xTextInput->toPlainText();
    QString y = ui.yTextInput->toPlainText();
    int intx = x.toInt(&okx);
    int inty = y.toInt(&oky);


    QString angle = ui.angleTextInput->toPlainText();
    int intAng = angle.toInt(&okAng);

    if (!(okx && oky && okAng))
        ui.statusBar->showMessage("Input field are empty or non-digital characters are present");
    else
    {
        ui.renderArea->updateShape(intx, inty, intAng);
        ui.statusBar->showMessage("Updated");
    }

}
