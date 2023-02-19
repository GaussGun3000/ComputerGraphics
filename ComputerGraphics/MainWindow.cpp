#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.formLayout->setSizeConstraint(QLayout::SetFixedSize);
    ui.verticalLayout_3->addLayout(ui.formLayout);
}

MainWindow::~MainWindow()
{}
