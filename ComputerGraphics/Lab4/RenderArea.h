#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <Qvector.h>

class RenderArea :
    public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent);
    bool updateSetup();

    QPoint getOffset();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    //methods
    void drawAxes(QPainter* painter, QPoint offset);

    //fields
};

