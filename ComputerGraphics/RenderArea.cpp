#include "RenderArea.h"

RenderArea::RenderArea(QWidget *parent)
{

}


void RenderArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPoint offset = getOffset();
	QPen penRectangle(QColor("black"));

	int w = width(); int h = height(); // getting display size

	painter.drawLine(0, offset.y(), w, offset.y()); // x axis
	painter.drawLine(offset.x(), 0, offset.x(), h); // y axis

	//painter.drawLine(0, offset.y() - 4, 0, offset.y() + 4);

	for (int coordX = w/2; coordX < w; coordX += 20) // marking x axis
	{
		painter.drawLine(coordX, offset.y() - 4, coordX, offset.y() + 4);
		painter.drawLine(w - coordX, offset.y() - 4, w - coordX, offset.y() + 4);
		//painter.drawLine(-width() / 2 + coordX, -2, -width() / 2 + coordX, 2);
	}

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
