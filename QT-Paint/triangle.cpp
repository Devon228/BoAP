#include "triangle.h"

Triangle::Triangle(qreal xc, qreal yc, qreal a, qreal b) : NPolygon(xc, yc, a, b)
{
    setColor(Qt::black);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    addPoint(QPointF(xc, yc+a));
    addPoint(QPointF(xc-a*sqrt(3)/2.0, yc-a/2.0));
    addPoint(QPointF(xc+a*sqrt(3)/2.0, yc-a/2.0));
    calcPer();
    calcArea();

    updateBoundingRect();
}
Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // addPoint(QPointF(center.x(), center.y()+a));
    // addPoint(QPointF(center.x()-a*sqrt(3)/2.0, center.y()-a/2.0));
    // addPoint(QPointF(center.x()+a*sqrt(3)/2.0, center.y()-a/2.0));
    calcPer();
    calcArea();

    updateBoundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);

    painter->drawPolygon(getStartNode(), 3);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}

