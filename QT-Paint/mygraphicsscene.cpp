#include "mygraphicsscene.h"
#include "figure.h"
#include "npolygon.h"
#include "ellipse.h"
#include "square.h"
#include "rect.h"
#include "circle.h"
#include "triangle.h"
#include "romb.h"
#include "hex.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
//#include "mainwindow.h"

MyGraphicsScene::MyGraphicsScene(QObject *parent) : QGraphicsScene(parent)
{
    selected_item = nullptr;
    selected_type = 0;
}
MyGraphicsScene::~MyGraphicsScene()
{

}

Figure *MyGraphicsScene::getSelectedItem()
{
    return selected_item;
}
void MyGraphicsScene::setSelectedType(int x)
{
    selected_type = x;
}


/*void MyGraphicsScene::beep()
{
    return;
}*/
void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (selected_type == 0)
        QGraphicsScene::mouseMoveEvent(event);
    else
    {
        qreal dx = fabs(drawFig->getCenter().x() - event->scenePos().x());
        //qreal dy = fabs(drawFig->getCenter().y() - event->scenePos().y());
        qreal scale = dx * 0.02;
        if (scale == 0)
            scale = 0.001;
        drawFig->doScale(scale/drawFig->getScale()); //P,Area
        drawFig->mySetScale(scale);
        drawFig->calcPer();
        drawFig->calcArea();
        //drawFig->setA(dx); //changeCoord
        //drawFig->setB(dy);
        drawFig->updateBoundingRect();
    }
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (selected_item != nullptr)
    {
        selected_item->setColor(selected_item->getColor()); //default color
        selected_item = nullptr;
    }


    if (selected_type == 0)
    {
        selected_item = static_cast<Figure*>(itemAt(event->scenePos(), QTransform()));

        if (selected_item != nullptr)
        {
            //NPolygon* selected_item_pol = static_cast<NPolygon*>(selected_item);
            QString str_per = "P: " + QString::number(selected_item->getPerimeter());
            QString str_area = "S: " + QString::number(selected_item->getArea());
            QPointF coord_center = selected_item->getCenter();
            QString str_xc = "Xc: " + QString::number(coord_center.x());
            QString str_yc = "Yc: " + QString::number(coord_center.y());
            emit signalOnSelect(str_per, str_area, str_xc, str_yc);

            selected_item->setPen(Qt::blue, 4);
            //MainWindow::addTxt(lab_txt);
        }
        else
        {
            QString str_per = "P: не выбрано"; //per
            QString str_area = "S: не выбрано"; //per
            QString str_xc = "Xc: не выбрано"; //per
            QString str_yc = "Yc: не выбрано";
            emit signalOnSelect(str_per, str_area, str_xc, str_yc);
        }
        //    QGraphicsScene::mousePressEvent(event);
    }
    else
    {
        qDebug() << selected_type;
        switch (selected_type)
        {
        case SquareT:{
            Square *item = new Square(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case RectT:{
            Rect *item = new Rect(event->scenePos().x(), event->scenePos().y(), 150, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case TriangleT:{
            Triangle *item = new Triangle(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case RombT:{
            Romb *item = new Romb(event->scenePos().x(), event->scenePos().y(), 100, 120);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case HexT:{
            Hex *item = new Hex(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case Star5T:{
            Star5 *item = new Star5(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case Star6T:{
            Star6 *item = new Star6(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case Star8T:{
            Star8 *item = new Star8(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case EllipseT:{
            Ellipse *item = new Ellipse(event->scenePos().x(), event->scenePos().y(), 150, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        case CircleT:{
            Circle *item = new Circle(event->scenePos().x(), event->scenePos().y(), 100, 100);
            item->setPos(event->pos());
            drawFig = item;
            break;
        }
        }
        addItem(drawFig);
    }

    QGraphicsScene::mousePressEvent(event);
}
