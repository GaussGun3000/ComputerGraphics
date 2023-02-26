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
    void updateReferencePoint(int x, int y);
    void updateAngle(int angle);
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    QPoint referencePoint; 
    int Angle;
    QPoint getOffset();
    QVector<QLineF> getRectLines(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
    void drawAxes(QPainter* painter, QPoint offset);
};

