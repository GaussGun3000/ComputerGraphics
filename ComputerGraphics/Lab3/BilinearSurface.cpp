#include "BilinearSurface.h"
#include "BilinearSurface.h"
#include <qvector3d.h>
#include <qdebug.h>
#include <QtGui>

BilinearSurface::BilinearSurface()
{
    m_cornerPoints = QVector<QVector3D>();
    m_cornerPoints.reserve(4);
    rotated = false;
}

void BilinearSurface::setCornerPoints(const QVector<QVector3D>& points)
{
    if (points.size() == 4)
    {
        m_cornerPoints = points;
        m_cornerPointsRotated = points;
    }
    else
        qDebug() << "incorrect number of corner points for billinear surface";
}

QVector<QVector3D> BilinearSurface::cornerPoints() const
{
    return m_cornerPoints;
}

QVector<QVector3D> BilinearSurface::cornerPointsRotated() const
{
    return m_cornerPointsRotated;
}

bool BilinearSurface::isRotated() const
{
    return rotated;
}


QVector<QVector3D> BilinearSurface::interpolate(int numStepsU, int numStepsV, float angleX, float angleY)
{
    if (angleX || angleY)
        rotated = true;
    else
        rotated = false;

    QVector<QVector3D> surfacePoints;
    numStepsU = qMax(4, numStepsU);
    numStepsV = qMax(4, numStepsV);

    QVector3D p1 = m_cornerPoints.at(0);
    QVector3D p2 = m_cornerPoints.at(1);
    QVector3D p3 = m_cornerPoints.at(2);
    QVector3D p4 = m_cornerPoints.at(3);

     QMatrix4x4 rotationX;
     rotationX.setToIdentity();
     rotationX.rotate(angleX, QVector3D(1, 0, 0));
     QMatrix4x4 rotationY;
     rotationY.setToIdentity();
     rotationY.rotate(angleY, QVector3D(0, 1, 0));

    // Interpolate the surface points using bilinear interpolation
    for (int i = 0; i <= numStepsU; i++) {
        float u = i / static_cast<float>(numStepsU);
        for (int j = 0; j <= numStepsV; j++) {
            float v = j / static_cast<float>(numStepsV);
            QVector3D point = (1 - u) * (1 - v) * p1 + u * (1 - v) * p2 + u * v * p3 + (1 - u) * v * p4;
            point = rotationY * (rotationX * point);
            surfacePoints.append(point);
        }
    }
    if(angleX || angleY)
        for (int i = 0; i < 4; i++)
            m_cornerPointsRotated[i] = rotationY * (rotationX * m_cornerPoints[i]) ;

    return surfacePoints;
}