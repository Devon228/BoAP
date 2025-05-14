#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::cout << "sdf" << std::endl;
    tree = AVLtree();
    AVLtree t = AVLtree();
    t.insert(2, "aboba");
    t.insert(0, "a");
    t.insert(5, "b");
    t.insert(6, "c");
    t.insert(7, "d");

    t.find(6);
    t.find(7);
    t.del(7);
    t.find(7);
    std::vector <std::pair <long long, std::string> > v;
    t.preTraverse(v);
    t.postTraverse(v);
    t.inTraverse(v);

    std::cout << "Del\n";
    t.del(6);
    t.preTraverse(v);
    t.del(0);
    t.preTraverse(v);
    t.del(2);
    t.preTraverse(v);
    t.del(5);
    t.preTraverse(v);
    std::cout << "eee\n";
    t.preTraverse(v);
    t.insert(228, "Asd");
    t.insert(1, "afs");
    t.insert(229, "bbbdfs");
    t.inTraverse(v);
    t.del(1);
    t.del(228);
    t.del(229);

    tree = AVLtree();
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget_2->insertColumn(0);
    ui->tableWidget_2->insertColumn(1);
    ui->tableWidget_3->insertColumn(0);
    ui->tableWidget_3->insertColumn(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updInT()
{
    std::vector <std::pair <long long, std::string> > v;
    tree.inTraverse(v);

    while (ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);

    for (int i = 0; i < v.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(v[i].first)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(v[i].second)));
    }
}
void MainWindow::updPreT()
{
    std::vector <std::pair <long long, std::string> > v;
    tree.preTraverse(v);

    while (ui->tableWidget_2->rowCount())
        ui->tableWidget_2->removeRow(ui->tableWidget_2->rowCount()-1);

    for (int i = 0; i < v.size(); i++)
    {
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::number(v[i].first)));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(v[i].second)));
    }
}
void MainWindow::updPostT()
{
    std::vector <std::pair <long long, std::string> > v;
    tree.postTraverse(v);

    while (ui->tableWidget_3->rowCount())
        ui->tableWidget_3->removeRow(ui->tableWidget_3->rowCount()-1);

    for (int i = 0; i < v.size(); i++)
    {
        ui->tableWidget_3->insertRow(i);
        ui->tableWidget_3->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget_3->setItem(i, 0, new QTableWidgetItem(QString::number(v[i].first)));
        ui->tableWidget_3->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(v[i].second)));
    }
}

void MainWindow::on_insertButton_clicked()
{
    long long key = ui->spinBox->value();
    std::string value = ui->lineEdit->text().toStdString();
    tree.insert(key, value);

    updPreT();
    updPostT();
    updInT();
}


void MainWindow::on_deleteButton_clicked()
{
    long long key = ui->spinBox_2->value();
    tree.del(key);

    updPreT();
    updPostT();
    updInT();
}


void MainWindow::on_findButton_clicked()
{
    long long key = ui->spinBox_3->value();

    QMessageBox msgBox;

    msgBox.setText(QString::fromStdString(tree.find(key)));

    msgBox.exec();
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;

    msgBox.setText(QString::fromStdString(tree.findNearestMinMax()));

    msgBox.exec();
}

