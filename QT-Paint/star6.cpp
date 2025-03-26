#include "star6.h"

Star6::Star6(qreal xc, qreal yc, qreal a, qreal b) : NPolygon(xc, yc, a, b)
{
    setColor(Qt::cyan);
    //setPen(def_color, 4);
    //qDebug() << a << " " << b;
    for (int i = 0; i < 6; i++)
    {
        qreal ang = 2 * 3.1415 * i / 6.0;
        addPoint(QPointF(xc+a*cos(ang), yc+a*sin(ang)));
        addPoint(QPointF(xc+a/2.0*cos(ang+3.1415/6.0), yc+a/2.0*sin(ang+3.1415/6.0)));
    }
    calcPer();
    calcArea();

    updateBoundingRect();
}
Star6::~Star6()
{

}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // clearNodes();
    // for (int i = 0; i < 6; i++)
    // {
    //     qreal ang = 2 * 3.1415 * i / 6.0;
    //     addPoint(QPointF(center.x()+a*cos(ang), center.y()+a*sin(ang)));
    //     addPoint(QPointF(center.x()+a/2.0*cos(ang+3.1415/6.0), center.y()+a/2.0*sin(ang+3.1415/8.0)));
    // }
    calcPer();
    calcArea();

    updateBoundingRect();

    painter->setBrush(*brush);
    painter->setPen(*pen);

    painter->drawPolygon(getStartNode(), 12);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}



