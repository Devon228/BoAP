/*#include "rectangle.h"

Rectangle::Rectangle(qreal x, qreal y, qreal sideSize) : Figure(x, y) {
    this->sideSize = sideSize;

    addPoint(QPointF(-sideSize, -sideSize));

    addPoint(QPointF(sideSize, -sideSize));
    addPoint(QPointF(sideSize, sideSize));
    addPoint (QPointF(-sideSize, sideSize));

    updateBoundingRect();

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawPolygon(getStartNode(), 4);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());
    update();
}
*/
