#include "mainwindow.h"
#include "ui_mainwindow.h"

std::mt19937 rnd(228);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Queue <int> a = Queue <int>();
    a = Queue <int> ({4, 3, 2, 1}); //check rvalue in memory
    Queue <int> b = Queue <int> (2, 3);
    Queue<int>::swap(a, b);
    a.push_back(b.front());
    a.push_back(b.back());
    while (!a.empty())
    {
        std::cout << a.front() << std::endl;
        a.pop_front();
    }

    std::cout << b.back() << std::endl;
    b.clear();

    for (int i = 1; i <= 5; i++)
    {
        QPixmap image;
        image.load("/home/dimas/Документы/LR7/Task_1/img/" + QString::number(i) + ".png");
        qimg.push_back(image);
    }
    qimg.first->prev = qimg.last;
    qimg.last->next = qimg.first; //now it's ring
    scene = new QGraphicsScene(this);

    cur = qimg.first;
    scene->addPixmap(cur->value);
    scene->setSceneRect(cur->value.rect());
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    cur = cur->prev;

    scene->clear();
    scene->addPixmap(cur->value);
    scene->setSceneRect(cur->value.rect());
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_pushButton_clicked()
{
    cur = cur->next;

    scene->clear();
    scene->addPixmap(cur->value);
    scene->setSceneRect(cur->value.rect());
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_szButton_clicked()
{
    QMessageBox msgBox;

    msgBox.setText("Size is " + QString::number(qimg.size()));

    msgBox.exec();
}


void MainWindow::on_pushButton_real_clicked()
{
    QString new_img_name = QFileDialog::getOpenFileName(this, tr("Open Png File"), "/home/dimas/Документы/LR7/Task_1/img/", tr("Png File (*.png)"));
    QPixmap image;
    image.load(new_img_name);
    qimg.push_back(image);
    qimg.first->prev = qimg.last;
    qimg.last->next = qimg.first; //now it's rings
}


void MainWindow::on_pushButton_3_clicked()
{
    if (qimg.size() == 1)
        return;

    qimg.pop_front();

    cur = qimg.first;
    scene->clear();
    scene->addPixmap(cur->value);
    scene->setSceneRect(cur->value.rect());
    ui->graphicsView->setScene(scene);

    qimg.first->prev = qimg.last;
    qimg.last->next = qimg.first; //now it's rings
}

