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
    void saveInputData(QPoint& upperLeft, QPoint& lowerRight);
    void generateSegments(uint32_t lineCount, uint32_t maxlen);
    QScopedPointer<CohenSutherland>& getRectData();

public slots:
    void updateButtonClicked();
    void inputButtonClicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QPoint pointInputLayoutSize;
    Ui::MainWindowClass ui;
    
};
