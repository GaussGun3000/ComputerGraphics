#pragma once
#include <QPointF>

class MyRect
{
public:
    MyRect(QPointF topLeft, QPointF topRight, QPointF bottomRight, QPointF bottomLeft);

private:
    QPointF m_topLeft;
    QPointF m_topRight;
    QPointF m_bottomRight;
    QPointF m_bottomLeft;

    bool isRectangle() const;
    qreal MyRect::distance2(QPointF p1, QPointF p2) const;
};

