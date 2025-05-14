#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , h(10)
{
    ui->setupUi(this);

    HashTable h = HashTable(6);
    h.insert(1);
    h.insert(228);
    h.insert(7);
    h.insert(5);
    h.erase(228);
    std::cout << h.find(1) << std::endl;
    std::cout << h.find(5) << std::endl;
    std::cout << h.find(7) << std::endl;
    std::cout << h.find(228) << std::endl;

    //h = TaskHashTable(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::upd()
{
    while (ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    while (ui->tableWidget->columnCount())
        ui->tableWidget->removeColumn(ui->tableWidget->columnCount()-1);

    ui->tableWidget->insertColumn(0);
    for (size_t i = 0; i < h.size(); i++)
    {
        if (!h[i]->empty())
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::number(h[i]->front().key)));

            for (size_t j = 0; j < h[i]->size(); j++) //iterator
            {
                if (j + 1 == ui->tableWidget->columnCount())
                    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, j+1, new QTableWidgetItem(QString::number((*h[i])[j].value)));
            }
        }
    }
}

void MainWindow::on_insertButton_clicked()
{
    h.insert(ui->spinBox->value());

    upd();
}


void MainWindow::on_eraseButton_clicked()
{
    h.erase(ui->spinBox_2->value());

    upd();
}


void MainWindow::on_findButton_clicked()
{
    QMessageBox msg;

    msg.setText(QString::number(h.find(ui->spinBox_3->value())));

    msg.exec();
}


void MainWindow::on_rndButton_clicked()
{
    h.rndTable();

    upd();
}


void MainWindow::on_mxButton_clicked()
{
    QMessageBox msg;

    msg.setText(QString::number(h.maxKeyValue()));

    msg.exec();
}

