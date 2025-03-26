#include "rect.h"

Rect::Rect(qreal xc, qreal yc, qreal a, qreal b) : NPolygon(xc, yc, a, b)
{
    setColor(Qt::yellow);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    addPoint(QPointF(xc-a, yc-b));
    addPoint(QPointF(xc+a, yc-b));
    addPoint(QPointF(xc+a, yc+b));
    addPoint (QPointF(xc-a, yc+b));
    calcPer();
    calcArea();

    updateBoundingRect();
}
Rect::~Rect()
{

}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // addPoint(QPointF(center.x()-a, center.y()-b));
    // addPoint(QPointF(center.x()+a, center.y()-b));
    // addPoint(QPointF(center.x()+a, center.y()+b));
    // addPoint (QPointF(center.x()-a, center.y()+b));
    calcPer();
    calcArea();

    updateBoundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);

    painter->drawPolygon(getStartNode(), 4);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}

