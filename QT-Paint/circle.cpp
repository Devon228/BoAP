#include "circle.h"

Circle::Circle(qreal xc, qreal yc, qreal a, qreal b) : Figure(xc, yc, a, b)
{
    setColor(Qt::green);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    addPoint(QPointF(xc-a, yc-a));
    addPoint(QPointF(xc+a, yc-a));
    addPoint(QPointF(xc+a, yc+a));
    addPoint (QPointF(xc-a, yc+a));
    calcPer();
    calcArea();

    updateBoundingRect();
}
Circle::~Circle()
{

}
void Circle::calcPer()
{
    per = 2 * 3.1415 * a;
}
void Circle::calcArea()
{
    area = 3.1415 * a * a;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // addPoint(QPointF(center.x()-a, center.y()-a));
    // addPoint(QPointF(center.x()+a, center.y()-a));
    // addPoint(QPointF(center.x()+a, center.y()+a));
    // addPoint (QPointF(center.x()-a, center.y()+a));
    calcPer();
    calcArea();

    updateBoundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);

    painter->drawEllipse(boundingRect());

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}

