#ifndef STAR8_H
#define STAR8_H

#include "npolygon.h"

class Star8 : public NPolygon
{
public:
    explicit Star8(qreal xc, qreal yc, qreal a, qreal b);
    ~Star8();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};
#endif // STAR8_H
