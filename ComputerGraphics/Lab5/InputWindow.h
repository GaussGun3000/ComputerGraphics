#pragma once
#include "ui_InputWindow.h"
#include <QDialog>

class InputWindow : public QDialog, public Ui::InputWindow
{
    Q_OBJECT
public:
    explicit InputWindow(QWidget* parent = nullptr);
 
public slots:
    void randomButtonClicked();
    void saveButtonClicked();
    void eMaxSpinBoxValueChanged();
    void eMinSpinBoxValueChanged();

private:
    void fillOldValues();

    Ui::InputWindow ui;
    // Add any additional functions for the secondary window here
};



