#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyString s1("asd");
    MyString s2("bsd");
    s1 += s2;

    for (int i = 0; i < s1.size(); i++)
        std::cout << s1[i];

    std::cout << "\n" << s1.find(s2) << "\n" << s1.compare(s2) << "\n";

    MyString s3 = s1.substr(1, 3);
    for (int i = 0; i < s3.size(); i++)
        std::cout << s3[i];
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() //strcpy
{
    ui->textEdit->te
}


void MainWindow::on_strcatB_clicked()
{

}


void MainWindow::on_strcmpB_clicked()
{

}


void MainWindow::on_strlen_clicked()
{

}


void MainWindow::on_strncpyB_clicked()
{

}


void MainWindow::on_strncatB_clicked()
{

}


void MainWindow::on_strncmpB_clicked()
{

}


void MainWindow::on_memcpyB_clicked()
{

}


void MainWindow::on_memcmpB_clicked()
{

}

