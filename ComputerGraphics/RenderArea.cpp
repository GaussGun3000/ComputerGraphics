#include "RenderArea.h"




RenderArea::RenderArea(QWidget *parent)
{

}


void RenderArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPoint offset = getOffset();
	QPen penRectangle(QColor("black"));
	painter.drawLine(0, offset.y(), width(), offset.y()); // x axis
	painter.drawLine(offset.x(), 0, offset.x(), height()); // y axis
	painter.setPen(penRectangle);
	painter.drawLines(getRectLines(QPointF(-10 + offset.x(), 10 + offset.y()), QPointF(20 + offset.x(), 10 + offset.y()),
		QPointF(20 + offset.x(), -10 + offset.y()), QPointF(-10 + offset.x(), -10 + offset.y()))); 
	QPen penPoint(QColor("red"));
	penPoint.setWidth(3);
	painter.setPen(penPoint);
	painter.drawPoint(offset); 
}

QPoint RenderArea::getOffset()
/**
*	Calculate cooridnates offset to shift (0,0) for markers to the center of the widget
*/
{
	return QPoint(this->width() / 2, this->height() / 2);
}

QVector<QLineF> RenderArea::getRectLines(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
{
	QVector<QLineF> linesVector(4);
	linesVector.append(QLineF(p1, p2));
	linesVector.append(QLineF(p2, p3));
	linesVector.append(QLineF(p3, p4));
	linesVector.append(QLineF(p4, p1));
	return linesVector;
}
