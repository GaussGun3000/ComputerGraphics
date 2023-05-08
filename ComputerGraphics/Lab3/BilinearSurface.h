#pragma once

#include <QObject>
#include <QVector>
#include <QOpenGLFunctions>
#include <QVector3D>

class BilinearSurface : protected QOpenGLFunctions
{
public:
    explicit BilinearSurface();
    virtual ~BilinearSurface();

    void setCornerPoints(const QVector<QVector3D>& points);
    QVector<QVector3D> cornerPoints() const;

    QVector<QVector3D> interpolate(int numStepsU, int numStepsV, float x, float y) const;

private:
    QVector<QVector3D> m_cornerPoints;
};

