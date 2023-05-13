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
	void setRectangle(QPoint& upperLeft, QPoint& lowerRight);
	void setBorder(QPoint& border);
	QRect getRectangle();
	QVector<uint32_t> getSegmentGeneratorParams();
	void lineSegmentsGenerator();
	QVector<QLineF> clipLines();

private:
	//methods
	uint32_t computeOutCode(const QPoint& point);

	//fields
	uint32_t generatorLineCount;
	uint32_t generatorMaxlen;

	QRect window;
	QVector<QLineF> lineSegments;
	QVector<QLineF> clippedLines; 
	QPoint border;
	
};