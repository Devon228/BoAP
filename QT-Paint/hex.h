#ifndef HEX_H
#define HEX_H

#include "npolygon.h"

class Hex : public NPolygon
{
public:
    explicit Hex(qreal xc, qreal yc, qreal a, qreal b);
    ~Hex();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};
#endif // HEX_H
