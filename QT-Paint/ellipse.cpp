#include "ellipse.h"

Ellipse::Ellipse(qreal xc, qreal yc, qreal a, qreal b) : Figure(xc, yc, a, b)
{
    setColor(Qt::green);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    addPoint(QPointF(xc-a, yc-b));
    addPoint(QPointF(xc+a, yc-b));
    addPoint(QPointF(xc+a, yc+b));
    addPoint(QPointF(xc-a, yc+b));
    calcPer();
    calcArea();

    updateBoundingRect();
}
Ellipse::~Ellipse()
{

}
void Ellipse::calcPer()
{
    per = 3.1415 * (3 * (a + b) - sqrtl((3*a+b)*(a+3*b)));
}
void Ellipse::calcArea()
{
    area = 3.1415 * a * b;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // addPoint(QPointF(center.x()-a, center.y()-b));
    // addPoint(QPointF(center.x()+a, center.y()-b));
    // addPoint(QPointF(center.x()+a, center.y()+b));
    // addPoint(QPointF(center.x()-a, center.y()+b));
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
