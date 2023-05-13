#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <Qvector.h>
#include <qscopedpointer.h>
#include "CohenSutherland.h"

class RenderArea :
    public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent);
    bool updateSetup();

    QPoint getOffset();

    QScopedPointer<CohenSutherland> cohenSutherland;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    //methods
    void drawAxes(QPainter* painter, QPoint offset);
    const QPen segmentPen = QPen(QColor("black"));
    const QPen clippedSegmentPen = QPen(QColor("blue"));
    //fields
};

