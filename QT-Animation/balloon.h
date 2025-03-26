#ifndef BALLOON_H
#define BALLOON_H

#include <ellipse.h>

class Balloon : public QGraphicsItem
{
public:
    explicit Balloon();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

    //void boom();
    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    void setDefaultBalloon();
    void bigger();
    int getBigX();
    int getBigY();

 private:
    Ellipse* el_big, *el_small, *el_down;
};

#endif // BALLOON_H
