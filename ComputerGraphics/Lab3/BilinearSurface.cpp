#include "BilinearSurface.h"
#include "BilinearSurface.h"
#include <qvector3d.h>
#include <qdebug.h>

BilinearSurface::BilinearSurface()
{
    m_cornerPoints = QVector<QVector3D>();
    m_cornerPoints.reserve(4);
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

QVector<QVector3D> BilinearSurface::interpolate(int numStepsU, int numStepsV, float x, float y) const
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

            // Create the rotation matrices
            float rotationX[3][3] = {
                {1,     0,      0},
                {0,  cos(x),  -sin(x)},
                {0,  sin(x),   cos(x)}
            };
            float rotationY[3][3] = {
                { cos(y),  0, sin(y)},
                {    0,  1,    0},
                {-sin(y),  0, cos(y)}
            };

            // Multiply the point with the rotation matrices
            point = QVector3D(
                rotationY[0][0] * rotationX[0][0] * point.x() +
                rotationY[0][1] * rotationX[0][1] * point.y() +
                rotationY[0][2] * rotationX[0][2] * point.z(), 

                rotationY[1][0] * rotationX[1][0] * point.x() +
                rotationY[1][1] * rotationX[1][1] * point.y() +
                rotationY[1][2] * rotationX[1][2] * point.z(),

                rotationY[2][0] * rotationX[2][0] * point.x() +
                rotationY[2][1] * rotationX[2][1] * point.y() +
                rotationY[2][2] * rotationX[2][2] * point.z()); 

            surfacePoints.append(point);
        }
    }

    return surfacePoints;
}