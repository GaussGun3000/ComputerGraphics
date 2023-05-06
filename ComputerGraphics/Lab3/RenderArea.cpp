#include "RenderArea.h"
#include "BilinearSurface.h"
#include <QtCore>
#include "qpen.h"
#include <QTextEdit>
#include <QSet>
#include <qscopedpointer.h>

RenderArea::RenderArea(QWidget *parent):
	surface(new BilinearSurface)
{

}

bool RenderArea::updateSurface(QVector<QVector3D>& points, float angleX, float angleY)
{
	
	return false;
}

void RenderArea::paintEvent(QPaintEvent* event)
{

}

inline uint qHash(const QPointF& p) {
	return qHash(QPair<qreal, qreal>(qRound(p.x()), qRound(p.y())));
}

bool RenderArea::hasDuplicates(const QVector<QPointF>& points) 
{
	QSet<QPointF> uniquePoints;
	for (const QPointF& point : points) {
		if (uniquePoints.contains(point)) {
			return true;
		}
		uniquePoints.insert(point);
	}
	return false;
}

QPoint RenderArea::getOffset()
/**
*	Calculate cooridnates offset to shift (0,0) for markers to the center of the widget
*/
{
	return QPoint(this->width() / 2, this->height() / 2);
}

