#include "romb.h"

Romb::Romb(qreal xc, qreal yc, qreal a, qreal b) : NPolygon(xc, yc, a, b)
{
    setColor(Qt::gray);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    addPoint(QPointF(xc-a, yc));
    addPoint(QPointF(xc, yc+b));
    addPoint(QPointF(xc+a, yc));
    addPoint (QPointF(xc, yc-b));
    calcPer();
    calcArea();

    updateBoundingRect();
}
Romb::~Romb()
{

}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // addPoint(QPointF(center.x()-a, center.y()));
    // addPoint(QPointF(center.x(), center.y()+b));
    // addPoint(QPointF(center.x()+a, center.y()));
    // addPoint (QPointF(center.x(), center.y()-b));
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

