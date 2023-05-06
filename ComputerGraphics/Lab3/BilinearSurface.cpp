#include "BilinearSurface.h"
#include "BilinearSurface.h"
#include <qvector3d.h>
#include <qdebug.h>

BilinearSurface::BilinearSurface()
{
    m_cornerPoints = QVector<QVector3D>();
}

BilinearSurface::~BilinearSurface()
{

}

void BilinearSurface::setCornerPoints(const QVector<QVector3D>& points)
{
    if (points.size() == 4)
        m_cornerPoints = points;
    else
        qDebug() << "incorrect number of corner points for billinear surface";
}

QVector<QVector3D> BilinearSurface::cornerPoints() const
{
    return m_cornerPoints;
}