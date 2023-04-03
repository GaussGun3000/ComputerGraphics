#include "ParabolicSpline.h"

ParabolicSpline::ParabolicSpline()
{

}

ParabolicSpline::ParabolicSpline(QVector<QPointF>& points)
{
    this->m_points = points;
    this->calcParabolas();
}

void ParabolicSpline::addPoint(const QPointF& point) 
{
    m_points.append(point);
}

bool ParabolicSpline::empty()
{
    return m_points.size() >= 5;
}

QVector<QPoint> ParabolicSpline::getPointsToRender()
{
    return QVector<QPoint>();
}

bool ParabolicSpline::comparePoints(QVector<QPointF>& points)
{
    int length = points.size();
    if (length != this -> m_points.size())
        return false;
    for (int i = 0; i < length; i++)
    {
        if (this->m_points[i] != points[i])
            return false;
    }
    return true;
}

void ParabolicSpline::calcParabolas() {
    m_coefficients.clear();

    int n = m_points.size();

    for (int i = 0; i < n - 1; i++) {
        double x1 = m_points[i].x();
        double x2 = m_points[i + 1].x();
        double y1 = m_points[i].y();
        double y2 = m_points[i + 1].y();

        double a = (y2 - y1) / ((x2 - x1) * (x2 + x1));
        double b = ((-2 * x1 * y2) + (2 * x2 * y1)) / ((x2 - x1) * (x2 + x1));
        double c = ((x1 * x1 * y2) - (x2 * x2 * y1)) / ((x2 - x1) * (x2 + x1));

        QVector<double> segmentCoefficients;
        segmentCoefficients.append(a);
        segmentCoefficients.append(b);
        segmentCoefficients.append(c);

        m_coefficients.append(segmentCoefficients);
    }
}

QPointF ParabolicSpline::interpolate(double x) {
    int n = m_points.size();

    // Find the segment that contains x
    int i = 0;
    while (i < n - 1 && m_points[i + 1].x() < x) {
        i++;
    }

    // Evaluate the parabolic function for the segment
    double a = m_coefficients[i][0];
    double b = m_coefficients[i][1];
    double c = m_coefficients[i][2];

    double y = a * x * x + b * x + c;

    return QPoint(x, y);
}
