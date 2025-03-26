#include "hex.h"

Hex::Hex(qreal xc, qreal yc, qreal a, qreal b) : NPolygon(xc, yc, a, b)
{
    setColor(Qt::magenta);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    addPoint(QPointF(xc+a, yc));
    addPoint(QPointF(xc+a/2.0, yc+a*sqrt(3)/2.0));
    addPoint(QPointF(xc-a/2.0, yc+a*sqrt(3)/2.0));
    addPoint(QPointF(xc-a, yc));
    addPoint(QPointF(xc-a/2.0, yc-a*sqrt(3)/2.0));
    addPoint(QPointF(xc+a/2.0, yc-a*sqrt(3)/2.0));

    calcPer();
    calcArea();

    updateBoundingRect();
}
Hex::~Hex()
{

}

void Hex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // addPoint(QPointF(center.x()+a, center.y()));
    // addPoint(QPointF(center.x()+a/2.0, center.y()+a*sqrt(3)/2.0));
    // addPoint(QPointF(center.x()-a/2.0, center.y()+a*sqrt(3)/2.0));
    // addPoint(QPointF(center.x()-a, center.y()));
    // addPoint(QPointF(center.x()-a/2.0, center.y()-a*sqrt(3)/2.0));
    // addPoint(QPointF(center.x()+a/2.0, center.y()-a*sqrt(3)/2.0));

    calcPer();
    calcArea();

    updateBoundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);

    painter->drawPolygon(getStartNode(), 6);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}

