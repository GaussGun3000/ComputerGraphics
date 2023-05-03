#pragma once

#include <QVector>
#include <QVector3D>

class BezierSurface {
public:
    BezierSurface();
    BezierSurface(const QVector<QVector3D>& controlPoints);

    void setControlPoints(const QVector<QVector3D>& controlPoints);
    void calculateSurface(int numUSteps, int numVSteps);
    void render();

private:
    QVector<QVector3D> m_controlPoints;
    QVector<QVector3D> m_surfacePoints;
};