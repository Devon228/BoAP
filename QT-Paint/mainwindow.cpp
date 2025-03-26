#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->resize(50, 50);
    ui->setupUi(this);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //graphicsView non scroll
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //graphicsView non scroll
    ui->graphicsView->setSceneRect(-ui->graphicsView->width() / 2, -ui->graphicsView->height() / 2, ui->graphicsView->width(), ui->graphicsView->height());
    //size of scene to scroll

    scene = new MyGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    connect(scene, &MyGraphicsScene::signalOnSelect, this, &MainWindow::updateLabelText);
    //all items  connect(scene->getSelectedItem(), &Figure::signalOnMove, this, &MainWindow::updateLabelText);
    //scene->addItem(new Ellipse());

    //updating scene
    upd_timer = new QTimer();
    connect(upd_timer, &QTimer::timeout, this, &MainWindow::updateScene);
    upd_timer->start(10);







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScene()
{
    //qDebug() << ui->menu->currentIndex();
    scene->setSelectedType(ui->menu->currentIndex());

    scene->update();
    if (scene->getSelectedItem() != nullptr)
    {
        ui->label->setText("P: " + QString::number(scene->getSelectedItem()->getPerimeter()));
        ui->label_3->setText("S: " + QString::number(scene->getSelectedItem()->getArea()));
        ui->label_2->setText("Xc: " + QString::number(scene->getSelectedItem()->getCenter().x()));
        ui->label_4->setText("Yc: " + QString::number(scene->getSelectedItem()->getCenter().y()));
    }
}

void MainWindow::updateLabelText(QString& p, QString& a, QString& xc, QString& yc)
{
    ui->label->setText(p);
    ui->label_3->setText(a);
    ui->label_2->setText(xc);
    ui->label_4->setText(yc);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    Figure* cur = scene->getSelectedItem();
    qDebug() << "CURAAAAAAAA" << cur;
    qreal rot = value * 3.6;

    if (cur != nullptr)
    {
        //cur->setRotation(value * 3.6);
        cur->doRotation(-cur->getRotation()); //P,Area
        cur->doRotation(rot);
        cur->mySetRotation(rot);
    }
}



void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    Figure* cur = scene->getSelectedItem();
    qreal scale = value * 0.05;
    if (scale == 0)
        scale = 0.001;
    qDebug() << scale;

    if (cur != nullptr)
    {
        //cur->setScale(scale);
        cur->doScale(scale/cur->getScale()); //P,Area
        cur->mySetScale(scale);
        cur->calcPer();
        cur->calcArea();
        ui->label->setText("P: " + QString::number(cur->getPerimeter()));
        ui->label_3->setText("S: " + QString::number(cur->getArea()));
    }
}
