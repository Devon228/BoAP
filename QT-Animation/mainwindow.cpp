#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаем объект Ellipse и устанавливаем его как центральный виджет
    //ellipseWidget = new Ellipse(this);

    //setCentralWidget(ellipseWidget);

    //ellipseWidget->setEllipse(100, 100, 50, 75);

    //ui->ellipseContainer->layout()->addWidget(ellipseWidget);
    scene = new QGraphicsScene(0, 0, 300, 300, this);
    ui->graphicsView->setScene(scene);

    bal = new Balloon(/*this*/);
    //el->setEllipse(100, 100, 50, 50);
    bal->setPos(100, 100);
    scene->addItem(bal);
    //el->hideEllipse(scene);
    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(onUpdateClick())); //коннект кнопки со слотом
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(onRemoveClick())); //коннект кнопки со слотом
    connect(ui->upButton, SIGNAL(clicked()), this, SLOT(onUpClick())); //коннект кнопки со слотом
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(onLeftClick())); //коннект кнопки со слотом
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(onRightClick())); //коннект кнопки со слотом
    connect(ui->downButton, SIGNAL(clicked()), this, SLOT(onDownClick())); //коннект кнопки со слотом

    // Устанавливаем размеры окна
    //resize(100, 100);
}

void MainWindow::onUpdateClick()
{
    scene->removeItem(bal);
    bal->setDefaultBalloon();
    bal->setPos(100, 100); //mapToScene
    scene->addItem(bal);
    scene->update();
    //el->setEllipse(100, 100, 25, 25);
    //scene->addItem(el);
}
void MainWindow::onRemoveClick()
{
    //0->1
    if (!isBoom && scene->items().contains(bal))
    {
        isBoom = 1;

        timer1 = new QTimer(this);
        connect(timer1, SIGNAL(timeout()), this, SLOT(bigger())); //isBoom->0
        timer1->start(50);
    }

    //if (Timer1->isActive())
      //  el->setPos(228, 228);
    //scene->update();
    //scene->removeItem(el);
    //scene->update();
    //el->setEllipse(100, 100, 25, 25);
    //scene->addItem(el);
}
void MainWindow::bigger()
{
    sec++;
    bal->bigger();
    //el->addH();
    //el->addW();
    //scene->removeItem(el);
    //Timer1->stop();
    scene->update();
    if (sec >= 12)
    {
        timer1->stop();
        scene->removeItem(bal);

        QPixmap boom_pixmap("/home/dimas/Документы/LR1_my/boom.png");
        boom_item = new QGraphicsPixmapItem(boom_pixmap);
        boom_item->setOffset(QPointF(bal->getBigX()-50, bal->getBigY()-50));
        scene->addItem(boom_item);

        timer2 = new QTimer(this);
        connect(timer2, SIGNAL(timeout()), this, SLOT(hideImg())); //isBoom->0
        timer2->start(1000);

        sec = 0;
    }
}
void MainWindow::hideImg()
{
    scene->removeItem(boom_item);
    timer2->stop();
    isBoom = 0;
}

void MainWindow::onUpClick()
{
    bal->moveUp();
    scene->update();
    //el->setEllipse(100, 100, 25, 25);
    //scene->addItem(el);
}
void MainWindow::onLeftClick()
{
    bal->moveLeft();
    scene->update();
    //el->setEllipse(100, 100, 25, 25);
    //scene->addItem(el);
}
void MainWindow::onRightClick()
{
    bal->moveRight();
    scene->update();
    //el->setEllipse(100, 100, 25, 25);
    //scene->addItem(el);
}
void MainWindow::onDownClick()
{
    bal->moveDown();
    scene->update();
    //el->setEllipse(100, 100, 25, 25);
    //scene->addItem(el);
}

MainWindow::~MainWindow()
{
    delete ui;
}
