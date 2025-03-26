#include "figure.h"


Figure::Figure(qreal xc, qreal yc, qreal new_a, qreal new_b)
{
    //setFlag(QGraphicsItem::ItemIsMovable); //переписать

    this->setCenter(xc, yc);
    a = new_a;
    b = new_b;

    this->setBrush(Qt::transparent);
    //this->setPen(def_color, 3);
    this->setColor(Qt::red);
    per = 0;
    area = 0;
    scale = 1;
    rotation = 0;

    arr_nodes = new QVector<QPointF>;
}
Figure::~Figure()
{

}

void Figure::clearNodes()
{
    arr_nodes->clear();
}



QPointF Figure::getCenter()
{
    return this->center;
}
qreal Figure::getA()
{
    return this->a;
}
qreal Figure::getB()
{
    return this->b;
}
qreal Figure::getPerimeter()
{
    return this->per;
}
qreal Figure::getArea()
{
    return this->area;
}
QColor Figure::getColor()
{
    return this->def_color;
}

void Figure::setCenter(qreal x, qreal y)
{
    center = QPointF(x, y);
}
void Figure::setA(qreal new_a)
{
    //a = new_a;
    for(QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        i->setX(i->x() / a);
        i->setX(i->x() *new_a);
    }
    a = new_a;
}
void Figure::setB(qreal new_b)
{
    //b = new_b;
    for(QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        i->setY(i->y() / b);
        i->setY(i->y() * new_b);
    }
    b = new_b;
}
void Figure::setBrush(QColor color)
{
    brush = new QBrush(color);
}
void Figure::setPen(QColor color, int width)
{
    pen = new QPen(color);
    pen->setWidth(width);
}
void Figure::setColor(QColor color)
{
    def_color = color;
    setPen(def_color, 4);
}

QPointF* Figure::getStartNode()
{
    return arr_nodes->begin();
}

int Figure::getNumNodes()
{
    return arr_nodes->size();
}

void Figure::addPoint(QPointF point)
{
    arr_nodes->push_back(point);
}

void Figure::updateBoundingRect()
{
    xL = 10000; yL = 10000; xR = -10000; yR = -10000;

    for(auto i = arr_nodes->begin(); i != arr_nodes->end(); i++){
        QPointF* point = static_cast<QPointF*>(i); //iterator QPointF*

        qreal pX = point->x();
        qreal pY = point->y();

        xL = xL > pX ? pX : xL;
        xR = xR < pX ? pX : xR;
        yL = yL > pY ? pY : yL;
        yR = yR < pY ? pY : yR;
    }
}

QRectF Figure::boundingRect() const
{
    return QRectF(QPointF(xL, yL), QPointF(xR, yR));
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    selected_point = nullptr;
    QPointF posClk = event->pos();
    QPointF* start = getStartNode();
    for(QPointF* i = start; i != arr_nodes->end(); i++){
        QPointF* point = i;
        if(QLineF(posClk.x(), posClk.y(), point->x(), point->y()).length() < 10) selected_point = point;
    }
    if(QLineF(posClk.x(), posClk.y(), center.x(), center.y()).length() < 10) selected_point = &center;
    if (selected_point != nullptr) qDebug() << selected_point->x() << ' ' << selected_point->y();
    //QGraphicsItem::mousePressEvent(event);
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //двигать всю фигуру за вершинку
    if(selected_point == nullptr)
    {
        QGraphicsItem::mouseMoveEvent(event);
        return;
    };

    qDebug() << "as" << event->pos().x() << " " << event->pos().y();

    //QPointF new_pos = mapToScene(event()->pos());
    qreal dx = -(selected_point->x() - event->scenePos().x());
    qreal dy = -(selected_point->y() - event->scenePos().y());
    for(QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        *i += QPointF(dx, dy);
    }
    center += QPointF(dx, dy);

    QString str_per = "P: " + QString::number(getPerimeter());
    QString str_area = "S: " + QString::number(getArea());
    QPointF coord_center = getCenter();
    QString str_xc = "Xc: " + QString::number(coord_center.x());
    QString str_yc = "Yc: " + QString::number(coord_center.y());
    //emit signalOnMove(str_per, str_area, str_xc, str_yc);
    //this->moveBy(dx, dy);
    updateBoundingRect();
    qDebug() << dx << " " << dy;

    //qDebug() << xL << ' ' << yL << ' ' << xR << ' ' << yR;
    QGraphicsItem::mouseMoveEvent(event);
}

void Figure::doScale(qreal scale)
{
    for (QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        *i *= scale;
        *i += (1 - scale)  * getCenter();
    }

    updateBoundingRect();
}

qreal Figure::getScale()
{
    return scale;
}
void Figure::mySetScale(qreal sc)
{
    scale = sc;
}

void Figure::doRotation(qreal rot)
{
    qDebug() << rot;
    rot = rot * 3.1415 / 180.0;
    for (QPointF* i = arr_nodes->begin(); i != arr_nodes->end(); i++)
    {
        QPointF prev = *i;
        i->setX(center.x() + (prev.x() - center.x()) * std::cos(rot) - (prev.y() - center.y()) * std::sin(rot));
        i->setY(center.y() + (prev.x() - center.x()) * std::sin(rot) + (prev.y() - center.y()) * std::cos(rot));
    }
    updateBoundingRect();
}

qreal Figure::getRotation()
{
    return rotation;
}
void Figure::mySetRotation(qreal rot)
{
    rotation = rot;
}


