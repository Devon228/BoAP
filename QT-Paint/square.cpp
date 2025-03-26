#include "square.h"

Square::Square(qreal xc, qreal yc, qreal a, qreal b) : NPolygon(xc, yc, a, b)
{
    setColor(Qt::yellow);
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
Square::~Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

    painter->drawPolygon(getStartNode(), 4);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}

