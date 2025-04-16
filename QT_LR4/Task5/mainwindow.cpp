#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Vector <int> vv(5, 5);
    // vv.push_back(5);
    // std::cout << vv.size();
    v = new Vector<Pair <Vector <int>, Vector <Pair<int,double> > > > ();
    cur = new Pair<Vector <int>, Vector <Pair<int,double> > > ();

    // cur->first.push_back(1);
    // cur->second.push_back(Pair(1, 0.5));
    // v->push_back(*cur);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCur()
{
    while (ui->tableWidget->columnCount())
        ui->tableWidget->removeColumn(ui->tableWidget->columnCount()-1);
    while (ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);
    for (int i = 0; i < cur->first.size(); i++)
    {
        if (ui->tableWidget->columnCount() <= i)
            ui->tableWidget->insertColumn(i);
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(cur->first[i])));
    }
    for (int i = 0; i < cur->second.size(); i++)
    {
        if (ui->tableWidget->columnCount() <= i)
            ui->tableWidget->insertColumn(i);
        ui->tableWidget->setItem(1, i, new QTableWidgetItem( QString::number(cur->second[i].first)));
        ui->tableWidget->setItem(2, i, new QTableWidgetItem(QString::number(cur->second[i].second)));
    }
}

void MainWindow::on_pushButton_clicked()
{
    cur->first.push_back(ui->spinBox->value());
    showCur();
}


void MainWindow::on_pushButton_2_clicked()
{
    cur->second.push_back(Pair(ui->spinBox_2->value(), ui->doubleSpinBox->value()));
    showCur();
}

void MainWindow::showV()
{
    while (ui->tableWidget_2->columnCount())
        ui->tableWidget_2->removeColumn(ui->tableWidget_2->columnCount()-1);
    while (ui->tableWidget_2->rowCount())
        ui->tableWidget_2->removeRow(ui->tableWidget_2->rowCount()-1);
    for (int j = 0; j < v->size(); j++)
    {
        ui->tableWidget_2->insertRow(3*j+0);
        ui->tableWidget_2->insertRow(3*j+1);
        ui->tableWidget_2->insertRow(3*j+2);
        for (int i = 0; i < v->at(j).first.size(); i++)
        {
            if (ui->tableWidget_2->columnCount() <= i)
                ui->tableWidget_2->insertColumn(i);
            ui->tableWidget_2->setItem(3*j+0, i, new QTableWidgetItem(QString::number(v->at(j).first[i])));
        }
        for (int i = 0; i < v->at(j).second.size(); i++)
        {
            if (ui->tableWidget_2->columnCount() <= i)
                ui->tableWidget_2->insertColumn(i);
            ui->tableWidget_2->setItem(3*j+1, i, new QTableWidgetItem( QString::number(v->at(j).second[i].first)));
            ui->tableWidget_2->setItem(3*j+2, i, new QTableWidgetItem(QString::number(v->at(j).second[i].second)));
    }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    v->push_back(*cur);
    cur->first.clear();
    cur->second.clear();
    showCur();
    showV();
}


void MainWindow::on_pushButton_4_clicked()
{
    v->pop_back();
    showV();
}


void MainWindow::on_pushButton_5_clicked()
{
    v->clear();
    showV();
}


void MainWindow::on_pushButton_6_clicked()
{
    int pos = ui->spinBox_3->value();
    int count = ui->spinBox_4->value();
    v->insert(v->cbegin()+pos, count, *cur);
    cur->first.clear();
    cur->second.clear();
    showCur();
    showV();
}


void MainWindow::on_pushButton_7_clicked()
{
    int from = ui->spinBox_5->value();
    int to = ui->spinBox_6->value();
    v->erase(v->cbegin()+from, v->cbegin()+to);
    showV();
}

