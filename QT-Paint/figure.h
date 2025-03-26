#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QLineF>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QDebug>
#include <cmath>

class Figure : public QGraphicsItem
{
public:
    Figure(qreal xc = 0, qreal yc = 0, qreal new_a = 150, qreal new_b = 50);
    ~Figure();

    QPointF getCenter();
    qreal getA();
    qreal getB();
    qreal getPerimeter();
    qreal getArea();
    QColor getColor();
    void setCenter(qreal x, qreal y);
    void setA(qreal new_a);
    void setB(qreal new_b);
    void setBrush(QColor color);
    void setPen(QColor color, int width);
    void setColor(QColor color);

    QPointF* getStartNode();
    int getNumNodes();
    void addPoint(QPointF point);
    void updateBoundingRect();

    virtual void calcPer() = 0; //virtual
    virtual void calcArea() = 0;//virtual
    //virtual void calcCenter() = 0;//virtual

    void doScale(qreal scale); //virtual
    qreal getScale();
    void mySetScale(qreal sc);

    void doRotation(qreal scale); //virtual | drawlElipse does not allow correct rotation
    qreal getRotation();
    void mySetRotation(qreal rot);

    void clearNodes();

protected:
    QRectF boundingRect() const override;//not virtual cause for ellipse boundingrect = arr_nodes

    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; //virtual?

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override; //virtual?

/*signals:
    void signalOnMove(QString& p, QString& a, QString& xc, QString& yc);*/


protected:
    QPointF center;
    qreal a, b;

    QBrush* brush;
    QPen* pen;
    QVector<QPointF>* arr_nodes;
    QPointF* selected_point; //change
    qreal xL, yL, xR, yR;
    qreal per, area;
    QColor def_color;
    qreal scale, rotation;
};

#endif // FIGURE_H
