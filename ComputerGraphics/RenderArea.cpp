#include "RenderArea.h"
#include "MyRect.h"
#include "qpen.h"
#include <QTextEdit>

RenderArea::RenderArea(QWidget *parent)
{
	referencePoint = QPoint(0,0); 
	angle = 0;
	myRect = MyRect();
}

void RenderArea::updateShape(int x, int y, int angle)
{
	if (this->referencePoint != QPointF(x, y) || this->angle != angle)
	{
		updateReferencePoint(x, y);
		updateAngle(angle);
		this->myRect.rotateRelativeToPoint(referencePoint, this->angle);
		this->update();
	}
}

void RenderArea::updateReferencePoint(int x, int y)
{
	referencePoint = QPointF(x,-y) + getOffset();
}

void RenderArea::updateAngle(int angle)
{
	this->angle = angle;
}

void RenderArea::drawAxes(QPainter* painter, QPoint offset)
{
	int w = width(); int h = height(); // getting display size

	painter->drawLine(0, offset.y(), w, offset.y()); // x axis
	painter->drawLine(offset.x(), 0, offset.x(), h); // y axis

	for (int coordX = w / 2; coordX < w; coordX += 50) // marking x axis
	{
		if (coordX != w / 2)
		{
			painter->drawLine(coordX, offset.y() - 4, coordX, offset.y() + 4);
			painter->drawLine(w - coordX, offset.y() - 4, w - coordX, offset.y() + 4);
			int signX = -w / 2 + coordX;
			painter->drawText(w - coordX, offset.y() + 15, QString::number(-signX)); // x < 0
			painter->drawText(coordX, offset.y() + 15, QString::number(signX)); // x > 0
		}
	}

	for (int coordY = h / 2; coordY < h; coordY += 50) // marking y axis
	{
		if (coordY != h / 2)
		{
			painter->drawLine(offset.x() - 4, coordY, offset.x() + 4, coordY);
			painter->drawLine(offset.x() - 4, h - coordY, offset.x() + 4, h - coordY);
			int signY = -h / 2 + coordY;
			painter->drawText(offset.x() + 15, coordY, QString::number(-signY)); // y < 0 
			painter->drawText(offset.x() + 15, h - coordY, QString::number(signY)); // y > 0 
		}
	}
}

void RenderArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPoint offset = getOffset();

	drawAxes(&painter, offset);

	QPen penRectangle(QColor("black"));
	painter.setPen(penRectangle);

	if (!myRect.isInit())
		myRect = MyRect (QPointF(-10, 10), QPointF(20, 10), QPointF(20, -10), QPointF(-10, -10), offset);

	painter.drawLines(this->myRect.getLines());


	QPen penPoint(QColor("red"));
	penPoint.setWidth(3);
	painter.setPen(penPoint);
	painter.drawPoint(offset); 

	QPen newPoint(QColor("blue"));
	newPoint.setWidth(3);
	painter.setPen(newPoint);
	painter.drawPoint(referencePoint);

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
