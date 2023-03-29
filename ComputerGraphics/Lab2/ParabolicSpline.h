#pragma once
#include <QVector>
#include <QPointF>


class ParabolicSpline
{
public:
	ParabolicSpline(QVector<QPoint>& points);
	QVector<QPoint> getPointsToRender();
	bool comparePoints(QVector<QPoint>& points);

	void addPoint(const QPointF& point); // not needed??

private:
	//methods
	void calcParabolas();
	QPointF interpolate(double x);

	//fields
	QVector<QPointF> m_points;
	QVector<QVector<double>> m_coefficients; // coefficients a, b, c for each segment of spline [ax^2 + bx + c]
};

