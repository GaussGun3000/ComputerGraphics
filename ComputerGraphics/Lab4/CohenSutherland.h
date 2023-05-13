#pragma once
#include <QVector>
#include <qpoint.h>
#include <qrect.h>
#include <qline.h>

class CohenSutherland
{
public:
	CohenSutherland();
	void setSegmentGeneratorParams(uint32_t lineCount, uint32_t maxlen);
	void setRectangle(QPoint upperLeft, QPoint lowerRight);
	QRect getRectangle();
	QVector<uint32_t> getSegmentGeneratorParams();
	void lineSegmentsGenerator();
	QVector<QLine> clipLines();

private:
	//methods
	uint32_t computeOutCode(const QPoint& point);

	//fields
	uint32_t generatorLineCount;
	uint32_t generatorMaxlen;

	QRect window;
	QVector<QLine> lineSegments;
	QVector<QLine> clippedLines;
	
};