#pragma once
#include "BilinearSurface.h"
#include <qwidget.h>
#include <qpainter.h>
#include <Qvector.h>
#include <qvector3d.h>
#include <qscopedpointer.h>

class RenderArea:
    public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent);
    bool updateSurface(QVector<QVector3D>& points, float angleX, float angleY);
    QPoint getOffset();

    QScopedPointer<BilinearSurface> surface;
    
protected:
    void paintEvent(QPaintEvent* event) override;
    bool hasDuplicates(const QVector<QPointF>& points);
private:
    
};

