#include "MainWindow.h"
#include "PointInputElement.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.PIElayout->layout());
    pointInputElements.reserve(10);
    for (int i = 0; i < 5; i++)
    {
        PointInputElement* pie = new PointInputElement(this, i + 1);
        pointInputElements.push_back(pie);
        QPoint border = ui.renderArea->getOffset();
        pie->setSpinBoxLimits(border);
        existingLayout->addWidget(pie);
    }
    this->adjustSize();
    this->setMinimumSize(this->size());
    ui.PIElayout->setMaximumHeight((pointInputElements[0]->height() + existingLayout->spacing()) * 5);
}

MainWindow::~MainWindow()
{}

void MainWindow::updateButtonClicked()
{
    // Add methods: to renderArea - the one that is called from here to compare
    // QVector of points from GUI to QVector of points of the spline. 
    // If different, create new spline, replacing the existing (should be private field of RenderArea)
}

void MainWindow::AddButtonClicked()
{
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.PIElayout->layout());
    ui.removeButton->setDisabled(false);
    if (pointInputElements.size() < 10)
    {
        PointInputElement* pie = new PointInputElement(this, pointInputElements.size() + 1);
        quint32 h = pie->height();
        ui.PIElayout->setMaximumHeight(ui.PIElayout->height() + h + existingLayout->spacing());
        pointInputElements.push_back(pie);
        QPoint border = ui.renderArea->getOffset();
        pie->setSpinBoxLimits(border);
        existingLayout->addWidget(pie);
    }
    if (pointInputElements.size() == 10)
    {
        ui.addButton->setDisabled(true);
        ui.statusBar->showMessage("10 points is maximum");
    }
}

void MainWindow::RemoveButtonClicked()
{
    QVBoxLayout* existingLayout = qobject_cast<QVBoxLayout*>(ui.PIElayout->layout());
    ui.addButton->setDisabled(false);
    if (pointInputElements.size() > 5) // check if there is any element in the layout
    {
        PointInputElement* pie = pointInputElements.takeLast(); // take the last PointInputElement object from the vector
        quint32 h = pie->height();
        existingLayout->removeWidget(pie); // remove it from the layout
        delete pie; 
        ui.PIElayout->setMaximumHeight(ui.PIElayout->height() - h - existingLayout->spacing());
        this->resize(this->width(), this->height() - h - existingLayout->spacing());
    }
    if (pointInputElements.size() == 5)
    {
        ui.removeButton->setDisabled(true);
        ui.statusBar->showMessage("There can't be less than 5 points!");
    }

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    for (auto pie : pointInputElements)
    {
        QPoint border = ui.renderArea->getOffset();
        pie->setSpinBoxLimits(border);
    }
}

