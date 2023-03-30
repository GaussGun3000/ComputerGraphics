#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <Qvector.h>
#include "ParabolicSpline.h"

class RenderArea:
    public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent);
    void updateSpline(QVector<QPoint>& points);
    QPoint getOffset();
    
protected:
    void paintEvent(QPaintEvent* event) override;
private:
//methods
    void drawAxes(QPainter* painter, QPoint offset);
//fields
    std::unique_ptr<ParabolicSpline> spline;
    QPen prevRectPen;
};

