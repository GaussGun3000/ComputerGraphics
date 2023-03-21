#pragma once
#include <QVector>
#include <QPointF>


class ParabolicSpline
{
public:
	ParabolicSpline();

	void addPoint();
	QPointF interpolate(double x);
private:
	//methods
	void calcParabolas();

	//fields
	QVector<QPointF> m_points;
	QVector<QVector<double>> m_coefficients; // coefficients a, b, c for each segment of spline [ax^2 + bx + c]
};

