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
    explicit PointInputElement(QWidget* parent = nullptr, int number = 0);

    void setSpinBoxLimits(QPoint& renderAreaBorder);

    QPointF getPoint();

    //desctuctor is unnecessary! Destructor call ->  this - layout - [other child widgets] <- deletion order

private:
    QLabel* numberLabel;
    QLabel* xLabel;
    QLabel* yLabel;
    QSpinBox* xSpinBox;
    QSpinBox* ySpinBox;
    QHBoxLayout* layout;
    QSpacerItem* spacer;
};

