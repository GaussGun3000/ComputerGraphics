#pragma once

#include <QObject>
#include <QVector>
#include <QOpenGLFunctions>
#include <QVector3D>

class BilinearSurface : protected QOpenGLFunctions
{
public:
    explicit BilinearSurface();

    void setCornerPoints(const QVector<QVector3D>& points);
    QVector<QVector3D> cornerPoints() const;
    QVector<QVector3D> cornerPointsRotated() const;
    bool isRotated() const;

    QVector<QVector3D> interpolate(int numStepsU, int numStepsV, float angleX, float angleY);

private:
    bool rotated;
    QVector<QVector3D> m_cornerPoints;
    QVector<QVector3D> m_cornerPointsRotated;
};

