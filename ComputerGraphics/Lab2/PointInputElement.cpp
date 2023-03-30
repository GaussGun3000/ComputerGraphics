#include "PointInputElement.h"
#include <QWidget>

PointInputElement::PointInputElement(QWidget* parent, int number)
{
    numberLabel = new QLabel(QString::number(number)+")");
    xLabel = new QLabel("X:");
    yLabel = new QLabel("Y:");
    xSpinBox = new QSpinBox();
    ySpinBox = new QSpinBox();
    layout = new QHBoxLayout();
    spacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    numberLabel->setFixedWidth(20);
    xLabel->setMaximumWidth(15);
    yLabel->setMaximumWidth(15);

    layout->addWidget(numberLabel);
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

QPoint PointInputElement::getPoint() {
    return QPoint(xSpinBox->value(), ySpinBox->value());
}

