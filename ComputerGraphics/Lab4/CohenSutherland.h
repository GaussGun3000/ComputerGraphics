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

	QPointF computeIntersection(const QLineF& line, int outcode);
	
	QVector<QLineF> clipLines();

	QVector<QLineF>& getUnclippedLines();

private:
	//methods
	uint32_t computeOutcode(const QPointF& point);

	//fields
	uint32_t generatorLineCount;
	uint32_t generatorMaxlen;

	QRect window;
	QVector<QLineF> lineSegments;
	QVector<QLineF> clippedLines; 
	QPoint border;

	const uint32_t Top = 0b1000;
	const uint32_t Bottom = 0b0100;
	const uint32_t Right = 0b0010;
	const uint32_t Left = 0b0001;
};