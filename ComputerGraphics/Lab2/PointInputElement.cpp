#include "PointInputElement.h"
#include <QWidget>

PointInputElement::PointInputElement(QWidget* parent)
{
    xLabel = new QLabel("X:");
    yLabel = new QLabel("Y:");
    xSpinBox = new QSpinBox();
    ySpinBox = new QSpinBox();
    layout = new QHBoxLayout();
    spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    xLabel->setMaximumWidth(15);
    yLabel->setMaximumWidth(15);

    layout->addWidget(xLabel);
    layout->addWidget(xSpinBox);
    layout->addSpacerItem(spacer);
    layout->addWidget(yLabel);
    layout->addWidget(ySpinBox);

    this->setLayout(layout);
}

void PointInputElement::setSpinBoxLimits(QPoint& renderAreaBorder)
{
    xSpinBox->setMaximum(renderAreaBorder.x());
    xSpinBox->setMinimum(-renderAreaBorder.x());
    ySpinBox->setMaximum(renderAreaBorder.y());
    ySpinBox->setMinimum(-renderAreaBorder.y());
}