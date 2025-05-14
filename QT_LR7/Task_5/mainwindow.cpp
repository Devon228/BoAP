#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Deque <int> d = Deque<int>({1, 2, 3, 4});
    d.push_front(0);
    d.push_back(5);
    d.push_back(228);
    d.pop_back();
    d.pop_front();
    d.pop_front();
    for (size_t i = 0; i < d.size(); i++)
        std::cout << d[i] << std::endl;
    for (Deque<int>::Iterator it = d.begin(); it != d.end(); it++)
        std::cout << *it << std::endl;

    ui->tableWidget->insertColumn(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updTable()
{
    while (ui->tableWidget->rowCount())
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);

    for (int i = 0; i < q.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(q[i])));
    }
}

void MainWindow::on_pushBackButton_clicked()
{
    q.push_back(ui->spinBox->value());

    updTable();
}


void MainWindow::on_pushFrontButton_clicked()
{
    q.push_front(ui->spinBox_2->value());

    updTable();
}


void MainWindow::on_popBackButton_clicked()
{
    if (!q.empty())
        q.pop_back();

    updTable();
}


void MainWindow::on_popFrontButton_clicked()
{
    if (!q.empty())
        q.pop_front();

    updTable();
}


void MainWindow::on_clearButton_clicked()
{
    q.clear();

    updTable();
}


void MainWindow::on_sizeButton_clicked()
{
    QMessageBox msg;

    msg.setText(QString::number(q.size()));

    msg.exec();
}


void MainWindow::on_emptyButton_clicked()
{
    QMessageBox msg;
    if (!q.empty())
        msg.setText("Not empty");
    else
        msg.setText("Empty");

    msg.exec();
}


void MainWindow::on_iButton_clicked()
{
    int i = ui->spinBox_3->value();

    QMessageBox msg;
    if (i < 0 || q.size() <= i)
        msg.setText("Out of range");
    else
        msg.setText(QString::number(q[i]));

    msg.exec();
}

