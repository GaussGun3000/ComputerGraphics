#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qlayout.h"
#include <QVector3D>
#include <QVector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveInputData(QVector<QVector3D>& points);
    QVector <QVector3D> getSurfaseData();

public slots:
    void updateButtonClicked();
    void inputButtonClicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QPoint pointInputLayoutSize;
    Ui::MainWindowClass ui;
    
};
