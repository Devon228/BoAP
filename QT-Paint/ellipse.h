#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellipse : public Figure
{
public:
    explicit Ellipse(qreal xc, qreal yc, qreal a, qreal b);
    ~Ellipse();

    void calcPer() override; //virtual
    void calcArea() override;//virtual

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // ELLIPSE_H
