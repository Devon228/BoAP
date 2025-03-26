#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QObject>
#include "figure.h"

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MyGraphicsScene(QObject *parent = nullptr);
    ~MyGraphicsScene();

    Figure* getSelectedItem();
    void setSelectedType(int x);

    enum FigureType
    {
        SquareT = 1,
        RectT,
        TriangleT,
        RombT,
        HexT,
        Star5T,
        Star6T,
        Star8T,
        EllipseT,
        CircleT
    };

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void signalOnSelect(QString& p, QString& a, QString& xc, QString& yc);

private:
    Figure* selected_item;
    Figure* drawFig;
    int selected_type;
};

#endif // CASTOMGRAPHICSSCENE_H
