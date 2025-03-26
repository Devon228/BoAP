#ifndef ROMB_H
#define ROMB_H

#include "npolygon.h"

class Romb : public NPolygon
{
public:
    explicit Romb(qreal xc, qreal yc, qreal a, qreal b);
    ~Romb();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // ROMB_H
