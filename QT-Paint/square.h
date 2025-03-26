#ifndef SQUARE_H
#define SQUARE_H

#include "npolygon.h"

class Square : public NPolygon
{
public:
    explicit Square(qreal xc, qreal yc, qreal a, qreal b);
    ~Square();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // SQUARE_H
