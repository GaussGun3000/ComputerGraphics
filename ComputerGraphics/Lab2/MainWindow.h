#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qlayout.h"
#include "PointInputElement.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateButtonClicked();
    void AddButtonClicked();
    void RemoveButtonClicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QVector<PointInputElement*> pointInputElements;
    QPoint pointInputLayoutSize;
    Ui::MainWindowClass ui;
    
};
