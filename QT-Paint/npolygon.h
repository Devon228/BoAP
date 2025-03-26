#ifndef NPOLYGON_H
#define NPOLYGON_H

#include <QPainter>
#include <QGraphicsItem>
#include <QColor>
#include "figure.h"
#include <cmath>

class NPolygon : public Figure
{
public:
    NPolygon(qreal xc, qreal yc, qreal a, qreal b);
    ~NPolygon();

    void calcPer() override;
    void calcArea() override;
    //void calcCenter() override;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

/*protected:
    QColor def_color = Qt::yellow;*/
};

#endif // NPOLYGON_H
