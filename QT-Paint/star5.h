#ifndef STAR5_H
#define STAR5_H

#include "npolygon.h"

class Star5 : public NPolygon
{
public:
    explicit Star5(qreal xc, qreal yc, qreal a, qreal b);
    ~Star5();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // STAR5_H
