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
    void saveInputData(PolyhedronSort::PolyhedronGeneratorSettings& settings);
    void generatePolyhedrons();
    PolyhedronSort::PolyhedronGeneratorSettings getGenSettings();

public slots:
    void updateButtonClicked();
    void inputButtonClicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QPoint pointInputLayoutSize;
    Ui::MainWindowClass ui;
    
};
