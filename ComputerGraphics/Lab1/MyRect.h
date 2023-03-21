#pragma once
#include <QPointF>
#include <qline.h>

class MyRect
{
public:
    MyRect(QPointF topLeft, QPointF topRight, QPointF bottomRight, QPointF bottomLeft, QPoint offset);
    MyRect();
    QVector<QLineF> getLines() const;
    bool rotateRelativeToPoint(QPointF& referencePoint, int angle);
    bool isInit();

private:
    QPointF m_topLeft;
    QPointF m_topRight;
    QPointF m_bottomRight;
    QPointF m_bottomLeft;
    bool initialized = false;

    bool isRectangle() const;
    qreal MyRect::distance2(QPointF p1, QPointF p2) const;


};

