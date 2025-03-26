#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
public:
    explicit Circle(qreal xc, qreal yc, qreal a, qreal b);
    ~Circle();

    void calcPer() override; //virtual
    void calcArea() override;//virtual

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};


#endif // CIRCLE_H
