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
    bool updateSpline(QVector<QPointF>& points);
    QPoint getOffset();
    
protected:
    void paintEvent(QPaintEvent* event) override;
    bool hasDuplicates(const QVector<QPointF>& points);
private:
//methods
    void drawAxes(QPainter* painter, QPoint offset);
//fields
    QPen prevRectPen;
};

