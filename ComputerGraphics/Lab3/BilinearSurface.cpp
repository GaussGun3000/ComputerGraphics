#include "BilinearSurface.h"
#include "BilinearSurface.h"
#include <qvector3d.h>
#include <qdebug.h>

BilinearSurface::BilinearSurface()
{
    m_cornerPoints = QVector<QVector3D>();
}

BilinearSurface::~BilinearSurface()
{

}

void BilinearSurface::setCornerPoints(const QVector<QVector3D>& points)
{
    if (points.size() == 4)
        m_cornerPoints = points;
    else
        qDebug() << "incorrect number of corner points for billinear surface";
}

QVector<QVector3D> BilinearSurface::cornerPoints() const
{
    return m_cornerPoints;
}

QVector<QVector3D> BilinearSurface::interpolate(int numStepsU, int numStepsV) const
{
    QVector<QVector3D> surfacePoints;

    // Make sure we have at least 4 steps in each direction
    numStepsU = qMax(4, numStepsU);
    numStepsV = qMax(4, numStepsV);

    // Get the four corner points of the bilinear surface
    QVector3D p1 = m_cornerPoints.at(0);
    QVector3D p2 = m_cornerPoints.at(1);
    QVector3D p3 = m_cornerPoints.at(2);
    QVector3D p4 = m_cornerPoints.at(3);

    // Interpolate the surface points using bilinear interpolation
    for (int i = 0; i <= numStepsU; i++) {
        float u = i / static_cast<float>(numStepsU);
        for (int j = 0; j <= numStepsV; j++) {
            float v = j / static_cast<float>(numStepsV);
            QVector3D point = (1 - u) * (1 - v) * p1 + u * (1 - v) * p2 + u * v * p3 + (1 - u) * v * p4;
            surfacePoints.append(point);
        }
    }

    return surfacePoints;
}