#ifndef RECT_H
#define RECT_H

#include "npolygon.h"

class Rect : public NPolygon
{
public:
    explicit Rect(qreal xc, qreal yc, qreal a, qreal b);
    ~Rect();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // RECT_H
