#include "CohenSutherland.h"
#include <QRandomGenerator>
#include <qdatetime.h>

CohenSutherland::CohenSutherland()
{
    border = QPoint(100, 100);
    window = QRect(-30, -30, 30, 30);
    lineSegments = QVector<QLineF>();
    clippedLines = QVector<QLineF>();
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

QPointF CohenSutherland::computeIntersection(const QLineF& line, int outcode)
{
    qreal x, y;

    if (outcode & Top)
    {
        x = line.x1() + (line.x2() - line.x1()) * (window.top() - line.y1()) / (line.y2() - line.y1());
        y = window.top();
    }
    else if (outcode & Bottom)
    {
        x = line.x1() + (line.x2() - line.x1()) * (window.bottom() - line.y1()) / (line.y2() - line.y1());
        y = window.bottom();
    }
    else if (outcode & Right)
    {
        y = line.y1() + (line.y2() - line.y1()) * (window.right() - line.x1()) / (line.x2() - line.x1());
        x = window.right();
    }
    else if (outcode & Left)
    {
        y = line.y1() + (line.y2() - line.y1()) * (window.left() - line.x1()) / (line.x2() - line.x1());
        x = window.left();
    }

    return QPointF(x, y);
}

QVector<QLineF> CohenSutherland::clipLines()
{
    QVector<QLineF> clippedLines;
    clippedLines.reserve(lineSegments.size());
    for (const auto& l : lineSegments)
    {
        QLineF line(l);
        // Calculate the outcodes for the endpoints of the line segment
        int startOutcode = computeOutcode(line.p1());
        int endOutcode = computeOutcode(line.p2());

        while (true)
        {
            // If both endpoints are inside the window, add the original line segment to the list of clipped lines and exit the loop
            if (!(startOutcode | endOutcode))
            {
                clippedLines.append(line);
                break;
            }

            // If the line segment is outside the window, discard it and exit the loop
            if (startOutcode & endOutcode)
            {
                break;
            }

            // Calculate the endpoint to be clipped and its outcode
            QPointF clippedPoint;
            int clippedOutcode;
            if (startOutcode)
            {
                clippedOutcode = startOutcode;
                clippedPoint = computeIntersection(line, startOutcode);
            }
            else
            {
                clippedOutcode = endOutcode;
                clippedPoint = computeIntersection(line, endOutcode);
            }

            // Update the endpoint with the clipped endpoint
            if (clippedOutcode == startOutcode)
            {
                line.setP1(clippedPoint);
                startOutcode = computeOutcode(clippedPoint);
            }
            else
            {
                line.setP2(clippedPoint);
                endOutcode = computeOutcode(clippedPoint);
            }
        }
    }

    return clippedLines;
}

QVector<QLineF>& CohenSutherland::getUnclippedLines()
{
    return lineSegments;
}

uint32_t CohenSutherland::computeOutcode(const QPointF& point)
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
