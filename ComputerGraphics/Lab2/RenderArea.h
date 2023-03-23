#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <Qvector.h>

class RenderArea:
    public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent);
    void updateShape(int x, int y, int angle);
    QPoint getOffset();
    
protected:
    void paintEvent(QPaintEvent* event) override;
private:
//methods
    void updateReferencePoint(int x, int y);
    void updateAngle(int angle);
    QVector<QLineF> getRectLines(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
    void drawAxes(QPainter* painter, QPoint offset);
//fields
    QPen prevRectPen;
    QPointF referencePoint;
    int angle;
};

