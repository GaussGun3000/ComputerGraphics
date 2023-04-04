#pragma once
#include <QVector>
#include <QPointF>
#include <QLine>


class ParabolicSpline
{
public:
	ParabolicSpline();
	ParabolicSpline(QVector<QPointF>& points);
	QVector<QPointF> getPointsToRender(QPoint& offset);
	QVector<QLineF> getLinesToRender(QVector<QPointF> points);
	QVector<QPointF> getSplinePoints(QPoint& offset);
	bool comparePoints(QVector<QPointF>& points);
	void sortPointsByX(QVector<QPointF>& points);

	void addPoint(const QPointF& point); // not needed??
	bool empty();
private:
	//methods
	void calcParabolas();
	void calcMinMaxX();
	QPointF interpolate(double x);

	//fields
	qint32 m_minX;
	qint32 m_maxX;
	QVector<QPointF> m_points;
	QVector<QVector<double>> m_coefficients; // coefficients a, b, c for each segment of spline [ax^2 + bx + c]
};

