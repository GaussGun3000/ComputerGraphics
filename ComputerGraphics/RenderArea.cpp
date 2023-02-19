#include "RenderArea.h"

RenderArea::RenderArea(QWidget *parent)
{

}


QPoint RenderArea::getOffset()
/**
*	Calculate cooridnates offset to shift (0,0) for markers to the center of the widget
*/
{
	return QPoint(this->width() / 2, this->height() / 2);
}