#ifndef ELLIPSE_H
#define ELLIPSE_H

//#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <iostream>

class Ellipse : public QGraphicsItem //x y inside qgraphicsitem
{
    //Q_OBJECT

public:
    explicit Ellipse(int x, int y, int width, int height);
    explicit Ellipse();
    void setEllipse(int new_x, int new_y, int new_width, int new_height);

public:
    //void paintEvent(QPaintEvent *event) override; // Переопределяем метод для отрисовки
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
public slots:
    void hideEllipse(QGraphicsScene *scene); //delete?
    bool moveUp();
    bool moveLeft();
    bool moveRight();
    bool moveDown();
    void bigger();
    void setPenColor(QColor color);
    void setBrushColor(QColor color);
    int getWidth();
    int getHeight();
    int getX();
    int getY();

private:
    int x_base, y_base, width, height;
    QColor brushColor = Qt::transparent, penColor = Qt::blue;

/*private:
    void advance(int phase) override;*/
};

#endif // ELLIPSE_H
