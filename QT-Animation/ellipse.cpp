#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(int x, int y, int width, int height/*QWidget *parent*/)
    : x_base(x), y_base(y), width(width), height(height) /*QWidget{parent}*/
{
    // Устанавливаем цвет фона на белый (опционально)
    //setStyleSheet("background-color: white;");
}
Ellipse::Ellipse() : Ellipse(0, 0, 50, 50)
{

}

QRectF Ellipse::boundingRect() const
{
    return QRectF(100, 100, width, height);
}

void Ellipse::setEllipse(int new_x, int new_y, int new_width, int new_height)
{
    x_base = new_x;
    y_base = new_y;
    width = new_width;
    height = new_height;
}

void Ellipse::setPenColor(QColor color)
{
    penColor = color;
}

void Ellipse::setBrushColor(QColor color)
{
    brushColor = color;
}

void Ellipse::bigger ()
{
    width += 5;
    height += 5;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); // Игнорируем параметр event, чтобы избежать предупреждений
    Q_UNUSED(widget); // Игнорируем параметр event, чтобы избежать предупреждений

    //QPainter painter(this); // Создаем объект QPainter для отрисовки

    // Устанавливаем черный цвет кисти
    //painter.setBrush(Qt::blue);

    //Рисуем через Pen тонкой линией
    QPen pen(penColor);
    pen.setWidth(5);
    QBrush brush(brushColor);

    painter->setPen(pen);
    painter->setBrush(brush);


    // Получаем размеры виджета

    // Рисуем эллипс в заданном месте
    painter->drawEllipse(QPointF(x_base, y_base), width, height); //center 100 100
}


void Ellipse::hideEllipse(QGraphicsScene *scene)
{
    scene->removeItem(this); // Скрываем виджет
    //for
    //timer
    //width, height, update
    //qpic boom
}

bool Ellipse::moveUp()
{
    if (y_base >= -150)
    {
        y_base -= 5;
        return 1;
    }
    return 0;
}
bool Ellipse::moveLeft()
{
    if (x_base >= -150)
    {
        x_base -= 5;
        return  1;
    }
    return 0;
}
bool Ellipse::moveRight()
{
    //std::cout << x();
    if (x_base <= 150)
    {
        x_base += 5;
        return 1;
    }
    return 0;
}
bool Ellipse::moveDown()
{
    if (y_base <= 150)
    {
        y_base += 5;
        return 1;
    }
    return 0;
}

int Ellipse::getWidth()
{
    return width;
}

int Ellipse::getHeight()
{
    return height;
}
int Ellipse::getX()
{
    return x_base;
}

int Ellipse::getY()
{
    return y_base;
}
/*
void Ellipse::advance(int phase)
{
    if (phase)
    {
        moveBy(0, -2);
        //moveBy(0, -2 * v);
        //v *= 1.05;
    }
}*/

