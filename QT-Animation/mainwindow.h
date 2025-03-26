#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QTimer>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QTimer>
#include <iostream>
#include "ellipse.h"
#include <balloon.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    Balloon *bal;
    QGraphicsScene *scene;
    QTimer *timer1, *timer2;
    QGraphicsPixmapItem* boom_item;
    int sec = 0;
    bool isBoom = 0;

private slots: //внутри мб private
     void onUpdateClick();
     void onRemoveClick();
     void onUpClick();
     void onLeftClick();
     void onRightClick();
     void onDownClick();
     void bigger();
     void hideImg();
};
#endif // MAINWINDOW_H
