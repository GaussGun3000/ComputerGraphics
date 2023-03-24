#include "MainWindow.h"
#include "PointInputElement.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.centralWidget->layout());
    pointInputElements.reserve(10);
    for (int i = 0; i < 5; i++)
    {
        PointInputElement* pie = new PointInputElement();
        pointInputElements.push_back(pie);
        QPoint border = ui.renderArea->getOffset();
        pie->setSpinBoxLimits(border);
        existingLayout->addWidget(pie);

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

void MainWindow::AddButtonClicked()
{
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.centralWidget->layout());
    if (pointInputElements.size() < 10)
    {
        PointInputElement* pie = new PointInputElement();
        pointInputElements.push_back(pie);
        QPoint border = ui.renderArea->getOffset();
        pie->setSpinBoxLimits(border);
        existingLayout->addWidget(pie);
    }
    else 
    {
        ui.statusBar->showMessage("Maximum number of points reached.");
    }
}

void MainWindow::RemoveButtonClicked()
{
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.centralWidget->layout());
    if (pointInputElements.size() > 5) // check if there is any element in the layout
    {
        PointInputElement* pie = pointInputElements.takeLast(); // take the last PointInputElement object from the vector
        existingLayout->removeWidget(pie); // remove it from the layout
        delete pie; // delete the object from memory
    }
    else 
    {
        ui.statusBar->showMessage("There are no points to remove.");
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    //handle window resize event here
    for (auto pie : pointInputElements)
    {
        QPoint border = ui.renderArea->getOffset();
        pie->setSpinBoxLimits(border);
    }
}

