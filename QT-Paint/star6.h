#ifndef STAR6_H
#define STAR6_H

#include "npolygon.h"

class Star6 : public NPolygon
{
public:
    explicit Star6(qreal xc, qreal yc, qreal a, qreal b);
    ~Star6();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};
#endif // STAR6_H
