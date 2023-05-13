#include "CohenSutherland.h"
#include <QRandomGenerator>
#include <qdatetime.h>

CohenSutherland::CohenSutherland()
{
    window = QRect(-30, -30, 30, 30);
    lineSegments = QVector<QLine>();
    clippedLines = QVector<QLine>();
}

void CohenSutherland::setSegmentGeneratorParams(uint32_t lineCount, uint32_t maxlen)
{
    generatorLineCount = lineCount;
    generatorMaxlen = maxlen;
}

void CohenSutherland::setRectangle(QPoint& upperLeft, QPoint& lowerRight)
{
    window = QRect(upperLeft, lowerRight);
}

void CohenSutherland::setBorder(QPoint& border)
{
    this->border = border;
}

QRect CohenSutherland::getRectangle()
{
    return window;
}

QVector<uint32_t> CohenSutherland::getSegmentGeneratorParams()
{
    QVector<uint32_t> genParams;
    genParams.append(generatorLineCount);
    genParams.append(generatorMaxlen);
    return genParams;
}

void CohenSutherland::lineSegmentsGenerator()
{
    uint32_t minLength;
    lineSegments.reserve(generatorLineCount);

    QRandomGenerator rng(QDateTime::currentMSecsSinceEpoch());

    for (int i = 0; i < generatorLineCount; i++)
    {
        QPoint start(rng.bounded(-border.x(), border.x()), rng.bounded(-border.y(), border.y()));
        QPoint end;
        do
        {
            end = QPoint(rng.bounded(-border.x(), border.x()), rng.bounded(-border.y(), border.y()));
        } while (QLineF(start, end).length() < 10);

        // Create the line segment and add it to the vector of segments
        lineSegments.append(QLineF(start, end));
    }
}

QVector<QLineF> CohenSutherland::clipLines()
{
    return QVector<QLineF>();
}

uint32_t CohenSutherland::computeOutCode(const QPoint& point)
{
    int outcode = 0;

    if (point.x() < window.left()) {       // Left of window
        outcode |= 0b0001;                 // Set left bit to 1
    }
    else if (point.x() > window.right()) { // Right of window
        outcode |= 0b0010;                 // Set right bit to 1
    }

    if (point.y() < window.top()) {        // Above window
        outcode |= 0b0100;                 // Set top bit to 1
    }
    else if (point.y() > window.bottom()) {// Below window
        outcode |= 0b1000;                 // Set bottom bit to 1
    }

    return outcode;
}
