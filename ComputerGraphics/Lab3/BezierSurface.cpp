#include "BezierSurface.h"

BezierSurface::BezierSurface()
{
	//
}

BezierSurface::BezierSurface(const QVector<QVector3D>& controlPoints) {
	setControlPoints(controlPoints);
}

BezierSurface::BezierSurface(const QVector<QVector3D>& controlPoints)
{
}

void BezierSurface::setControlPoints(const QVector<QVector3D>& controlPoints)
{
}

void BezierSurface::calculateSurface(int numUSteps, int numVSteps)
{
}

void BezierSurface::render()
{
}
