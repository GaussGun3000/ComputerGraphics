#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <memory>

class PointInputElement : public QWidget
{
    Q_OBJECT

public:
    explicit PointInputElement(QWidget* parent = nullptr);

    void setSpinBoxLimits(QPoint& renderAreaBorder);

    //desctuctor is unnecessary! Destructor call ->  this - layout - [other child widgets] <- deletion order

private:
    QLabel* xLabel;
    QLabel* yLabel;
    QSpinBox* xSpinBox;
    QSpinBox* ySpinBox;
    QHBoxLayout* layout;
    QSpacerItem* spacer;
};

