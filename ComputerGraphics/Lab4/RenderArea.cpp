#include "RenderArea.h"
#include <QtCore>
#include "qpen.h"
#include <QTextEdit>
#include <QSet>

RenderArea::RenderArea(QWidget* parent): cohenSutherland(new CohenSutherland)
{
	clippedLinesPen = QPen(Qt::red, 2);
	originalLinesPen = QPen(Qt::black);
}

bool RenderArea::updateSetup()
{
	auto offset = getOffset();
	cohenSutherland->setBorder(offset);
	this->update();
	return false;
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
			//y directed from top to bottom
			painter->drawText(offset.x() + 15, coordY, QString::number(signY)); // y > 0 
			painter->drawText(offset.x() + 15, h - coordY, QString::number(-signY)); // y < 0 
		}
	}
}

void RenderArea::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPoint offset = getOffset();
	cohenSutherland->setBorder(offset);	
	drawAxes(&painter, offset);
	drawRectangle(&painter, offset);
	drawLines(&painter, offset);
	drawClippedLines(&painter, offset);

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

void RenderArea::drawRectangle(QPainter* painter, QPoint& offset)
{
	QPen penRect(Qt::blue);
	penRect.setWidth(2);
	painter->setPen(penRect);
	QRect rect = this->cohenSutherland->getRectangle();
	painter->drawRect(QRect(rect.topLeft() + getOffset(), rect.bottomRight() + getOffset()));
}

void RenderArea::drawLines(QPainter* painter, QPoint& offset)
{
	painter->setPen(originalLinesPen);
	if (!this->cohenSutherland->getUnclippedLines().isEmpty())
	{
		QVector<QLineF> lines = this->cohenSutherland->getUnclippedLines();
		for (int i = 0; i < lines.size(); i++)
		{
			painter->drawLine(
				QLineF(QPointF(lines[i].p1() + getOffset()), QPointF(lines[i].p2() + getOffset())));
		}
	}
}

void RenderArea::drawClippedLines(QPainter* painter, QPoint& offset)
{
	painter->setPen(clippedLinesPen);
	if (!this->cohenSutherland->getUnclippedLines().empty()) 
	{
		QVector<QLineF> lines = this->cohenSutherland->clipLines();
		for (auto line: lines)
		{
			painter->drawLine(
				QLineF(QPointF(line.p1() + getOffset()), QPointF(line.p2() + getOffset())));
		}
	}
}

