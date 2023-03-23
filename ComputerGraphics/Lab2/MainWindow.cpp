#include "MainWindow.h"
#include "PointInputElement.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.centralWidget->layout());
    std::vector<PointInputElement*> points;
    points.reserve(10);

    for (int i = 0; i < 5; i++)
    {
        points.push_back(new PointInputElement());
        existingLayout->addWidget(points[i]);
    }
}

MainWindow::~MainWindow()
{}

void MainWindow::updateButtonClicked()
{

    bool okx, oky, okAng;

   /* QString x = ui.xTextInput->toPlainText();
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
    }*/

}
