#include "PointInputElement.h"
#include <QWidget>

PointInputElement::PointInputElement(QWidget* parent)
{
    xLabel = std::make_unique<QLabel>("X:");
    yLabel = std::make_unique<QLabel>("Y:");
    xSpinBox = std::make_unique<QDoubleSpinBox>();
    ySpinBox = std::make_unique<QDoubleSpinBox>();
    layout = std::make_unique<QHBoxLayout>();

    layout->addWidget(xLabel.get());
    layout->addWidget(xSpinBox.get());
    layout->addWidget(yLabel.get());
    layout->addWidget(ySpinBox.get());

    this->setLayout(layout.get()); 
}
