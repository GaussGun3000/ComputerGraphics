#include "CohenSutherland.h"

CohenSutherland::CohenSutherland()
{
    window = QRect(-30, -30, 30, 30);
    lineSegments = QVector<QLine>();
    clippedLines = QVector<QLine>();
}

void CohenSutherland::setRectangle(QPoint upperLeft, QPoint lowerRight)
{
    window = QRect(upperLeft, lowerRight);
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
