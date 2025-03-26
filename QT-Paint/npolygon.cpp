#include "npolygon.h"


NPolygon::NPolygon(qreal xc, qreal yc, qreal a, qreal b) : Figure(xc, yc, a, b)
{
    //setColor(Qt::yellow);
    //setPen(def_color, 4);

    /*addPoint(QPointF(-50, -50));
    addPoint(QPointF(50, -50));
    addPoint(QPointF(50, 50));
    addPoint (QPointF(-50, 50));*/
    //calcPer();
    //calcArea();
    //calcCenter();

    //updateBoundingRect();
}

NPolygon::~NPolygon()
{

}

void NPolygon::calcPer()
{
    per = 0;
    for (QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        if (i + 1 == arr_nodes->end())
            per += (QLineF(*i, *(arr_nodes->begin()))).length();
        else
            per += (QLineF(*i, *(i+1))).length();
    }
}
void NPolygon::calcArea()
{
    area = 0;
    for (QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        if (i + 1 == arr_nodes->end())
            area += ((i)->y() + (arr_nodes->begin())->y()) * ((i)->x() - (arr_nodes->begin())->x());
        else
            area += ((i)->y() + (i+1)->y()) * ((i)->x() - (i+1)->x());
    }
    area = fabs(area) / 2;
}

/*
void NPolygon::calcCenter()
{
    //default 0, 0
    for (QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        center += QPointF(i->x(), i->y());
    }

    center /= getNumNodes();
}
*/

void NPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(*brush);
    painter->setPen(*pen);
    painter->drawPolygon(arr_nodes->begin(), 4);

    painter->setPen(Qt::DotLine);
    painter->drawRect(boundingRect());

    painter->setPen(Qt::transparent);
    painter->setBrush(def_color);
    painter->drawEllipse(center, 5, 5);
}
