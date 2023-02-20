#include "MyRect.h"
#include <qalgorithms.h>

qreal MyRect::distance2(QPointF p1, QPointF p2) const
{
    return (p1.x() - p2.x()) * (p1.x() - p2.x()) + (p1.y() - p2.y()) * (p1.y() - p2.y());
}

bool MyRect::isRectangle() const {
    // Check if any three points are collinear
    if (qFuzzyCompare(m_topLeft.x(), m_topRight.x()) && qFuzzyCompare(m_topRight.x(), m_bottomRight.x()) && qFuzzyCompare(m_bottomRight.x(), m_bottomLeft.x())) return false;
    if (qFuzzyCompare(m_topLeft.y(), m_topRight.y()) && qFuzzyCompare(m_topRight.y(), m_bottomRight.y()) && qFuzzyCompare(m_bottomRight.y(), m_bottomLeft.y())) return false;

    // Calculate distances between all pairs of points
    qreal d2[6];
    d2[0] = distance2(m_topLeft, m_topRight);
    d2[1] = distance2(m_topLeft, m_bottomRight);
    d2[2] = distance2(m_topLeft, m_bottomLeft);
    d2[3] = distance2(m_topRight, m_bottomRight);
    d2[4] = distance2(m_topRight, m_bottomLeft);
    d2[5] = distance2(m_bottomRight, m_bottomLeft);

    // Sort distances in non-decreasing order
    qSort(d2, d2 + 6);

    // Check if the first two distances are equal and the last four distances are equal
    return qFuzzyCompare(d2[0], d2[1]) && qFuzzyCompare(d2[1], d2[2]) && qFuzzyCompare(d2[2], d2[3]) && qFuzzyCompare(d2[3], d2[4]) && qFuzzyCompare(d2[4], d2[5]);
}

MyRect::MyRect(QPointF topLeft, QPointF topRight, QPointF bottomRight, QPointF bottomLeft) :
    m_topLeft(topLeft),
    m_topRight(topRight),
    m_bottomRight(bottomRight),
    m_bottomLeft(bottomLeft)
{
    if (!isRectangle()) {
        // if the points do not form a rectangle, use default points
        m_topLeft = QPointF(-20, 20);
        m_topRight = QPointF(20, 20);
        m_bottomRight = QPointF(20, -20);
        m_bottomLeft = QPointF(-20, -20);
    }
}

