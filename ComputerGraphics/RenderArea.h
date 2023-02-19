#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <vector>

class RenderArea :
    public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent);
private:
    QPoint getOffset();


};

