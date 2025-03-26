#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "npolygon.h"

class Triangle : public NPolygon
{
public:
    explicit Triangle(qreal xc, qreal yc, qreal a, qreal b);
    ~Triangle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // TRIANGLE_H
