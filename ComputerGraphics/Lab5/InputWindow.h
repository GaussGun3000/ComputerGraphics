#pragma once
#include "ui_InputWindow.h"
#include <QDialog>

class InputWindow : public QDialog, public Ui::InputWindow
{
    Q_OBJECT
public:
    explicit InputWindow(QWidget* parent = nullptr);
 
public slots:
    void saveButtonClicked();
    void fMaxSpinBoxValueChanged();
    void fMinSpinBoxValueChanged();

private:
    void fillOldValues();

    uint32_t factorial(uint32_t n);
    uint32_t calcMinV(uint32_t maxF);

    Ui::InputWindow ui;
    // Add any additional functions for the secondary window here
};



