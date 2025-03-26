#include "balloon.h"

Balloon::Balloon()
{
    el_big = new Ellipse(0, 0, 50, 60);
    el_small = new Ellipse(-20, -20, 10, 15);
    el_down = new Ellipse(0, 65, 5, 5);
    el_small->setRotation(90); //todo
}
QRectF Balloon::boundingRect() const
{
    return QRectF(100, 100, el_big->getWidth(), el_big->getHeight());
}


void Balloon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); // Игнорируем параметр event, чтобы избежать предупреждений
    Q_UNUSED(widget); // Игнорируем параметр event, чтобы избежать предупреждений

    //QPainter painter(this); // Создаем объект QPainter для отрисовки

    // Устанавливаем черный цвет кисти
    //painter.setBrush(Qt::blue);

    //Рисуем через Pen тонкой линией
    el_big->setPenColor(QColor(0, 0, 255, 200));
    el_big->setBrushColor(QColor(0, 0, 255, 200));
    el_big->paint(painter, option);

    el_down->setPenColor(QColor(0, 0, 255, 200));
    el_down->setBrushColor(QColor(0, 0, 255, 200));
    el_down->paint(painter, option);

    el_small->setPenColor(QColor(255, 255, 255, 150));
    el_small->setBrushColor(QColor(255, 255, 255, 150));
    el_small->paint(painter, option);

    //painter->setPen(pen);
    //painter->setBrush(brush);


    // Получаем размеры виджета

    // Рисуем эллипс в заданном месте
    //painter->drawEllipse(0, 0, width, height); //100 100
}

void Balloon::moveUp()
{
    if (el_small->moveUp())
    {
        el_big->moveUp();
        el_down->moveUp();
    }
}
void Balloon::moveLeft()
{
    if (el_small->moveLeft())
    {
        el_big->moveLeft();
        el_down->moveLeft();
    }
}
void Balloon::moveRight()
{
    //std::cout << x();
    if (el_big->moveRight())
    {
        el_small->moveRight();
        el_down->moveRight();
    }
}
void Balloon::moveDown()
{
    if (el_down->moveDown())
    {
        el_big->moveDown();
        el_small->moveDown();
    }
}

void Balloon::setDefaultBalloon()
{
    el_big->setEllipse(0, 0, 50, 60);
    el_small->setEllipse(-20, -20, 10, 15);
    el_down->setEllipse(0, 65, 5, 5);
}
void Balloon::bigger()
{
    el_big->bigger();
    el_small->bigger();
    el_down->moveDown();
}

int Balloon::getBigX()
{
    return el_big->getX();
}
int Balloon::getBigY()
{
    return el_big->getY();
}

