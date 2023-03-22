#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <memory>

class PointInputElement: QWidget
{
	Q_OBJECT

public:
    explicit PointInputElement(QWidget* parent = nullptr);

private:
    std::unique_ptr<QLabel> xLabel;
    std::unique_ptr<QLabel> yLabel;
    std::unique_ptr<QDoubleSpinBox> xSpinBox;
    std::unique_ptr<QDoubleSpinBox> ySpinBox;
    std::unique_ptr<QHBoxLayout> layout;
};

