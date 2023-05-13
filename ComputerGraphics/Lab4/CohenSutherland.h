#pragma once
#include <QVector>
#include <qpoint.h>
#include <qrect.h>
#include <qline.h>

class CohenSutherland
{
public:
	CohenSutherland();
	void setRectangle(QPoint upperLeft, QPoint lowerRight);
	QRect getRectangle();
	void lineSegmentsGenerator(uint32_t lineCount, uint32_t maxlen);
	QVector<QLine> clipLines();

private:
	//methods
	uint32_t computeOutCode(const QPoint& point);

	//fields
	QRect window;
	QVector<QLine> lineSegments;
	QVector<QLine> clippedLines;
	
};