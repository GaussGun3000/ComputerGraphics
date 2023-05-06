#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qlayout.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateButtonClicked();
    void inputButtonClicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QPoint pointInputLayoutSize;
    Ui::MainWindowClass ui;
    
};
