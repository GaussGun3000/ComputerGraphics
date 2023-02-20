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

	for (int coordX = w / 2; coordX < w; coordX += 50) // marking x axis
	{
		if (coordX != w / 2) 
		{
			painter.drawLine(coordX, offset.y() - 4, coordX, offset.y() + 4); 
			painter.drawLine(w - coordX, offset.y() - 4, w - coordX, offset.y() + 4);
			int signX = -w / 2 + coordX;
			painter.drawText(w - coordX, offset.y() + 15, QString::number(-signX)); // x < 0
			painter.drawText(coordX, offset.y() + 15, QString::number(signX)); // x > 0
		}
	}

	for (int coordY = h / 2; coordY < h; coordY += 50) // marking y axis
	{
		if (coordY != h / 2)
		{
			painter.drawLine(offset.x() - 4, coordY, offset.x() + 4, coordY);
			painter.drawLine(offset.x() - 4, h - coordY, offset.x() + 4, h - coordY);
			int signY = -h / 2 + coordY;
			painter.drawText(offset.x() + 15, coordY, QString::number(-signY)); // y < 0 
			painter.drawText(offset.x() + 15, h - coordY, QString::number(signY)); // y > 0 
		}
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
