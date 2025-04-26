#include "mainwindow.h"
#include "ui_mainwindow.h"

std::mt19937 rnd(228);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Bitset a(8, 5);
    Bitset b(7, 127);
    //b = a;
    std::cout << (b != a) << "\n";
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a.set();
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a.flip(7);
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a.flip();
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a[7] = 0;
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a.reset();
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a |= b;
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    ui->setupUi(this);

    numA = Bitset(1, 0);
    numB = Bitset(1, 1);
    showNumA();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNumA()
{
    while (ui->tableWidgetA->columnCount())
        ui->tableWidgetA->removeColumn(ui->tableWidgetA->columnCount()-1);

    for (int i = 0; i < numA.size(); i++)
    {
        ui->tableWidgetA->insertColumn(i);
        ui->tableWidgetA->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(numA.size()-1-i)));
        ui->tableWidgetA->setItem(0, i, new QTableWidgetItem(QString::number(numA.get(numA.size()-1-i))));
    }
}
void MainWindow::showNumB()
{
    while (ui->tableWidgetB->columnCount())
        ui->tableWidgetB->removeColumn(ui->tableWidgetB->columnCount()-1);

    for (int i = 0; i < numB.size(); i++)
    {
        ui->tableWidgetB->insertColumn(i);
        ui->tableWidgetB->setHorizontalHeaderItem(i, new QTableWidgetItem(QString::number(numB.size()-1-i)));
        ui->tableWidgetB->setItem(0, i, new QTableWidgetItem(QString::number(numB.get(numB.size()-1-i))));
    }
}

void MainWindow::on_rnd_clicked()
{
    numA = Bitset(129);
    for (int i = 0; i < 129; i++)
        numA[i] = rnd() % 2;

    showNumA();
}


void MainWindow::on_addDigit_clicked()
{
    numA = (Bitset(numA.size()+1, 0) | numA);
    numA[numA.size()-1] = ui->spinBoxA->value();

    showNumA();
}


void MainWindow::on_removeDigit_clicked()
{
    if (numA.size() > 1)
        numA = (Bitset(numA.size()-1, 0) | numA);

    showNumA();
}


void MainWindow::on_count_clicked()
{
    //std::cout << numA.size()-1 << "\n";
    ui->labelCount->setText(QString::number(numA.count()));
}


void MainWindow::on_flip_clicked()
{
    if (ui->spinFlip->value() >= (int)numA.size())
        return;

    if (ui->spinFlip->value() == -1)
        numA.flip();
    else
        numA.flip(ui->spinFlip->value());
    showNumA();
}


void MainWindow::on_set_clicked()
{
    if (ui->spinSet->value() >= (int)numA.size())
        return;

    if (ui->spinSet->value() == -1)
        numA.set();
    else
        numA.set(ui->spinSet->value());
    showNumA();
}


void MainWindow::on_reset_clicked()
{
    if (ui->spinReset->value() >= (int)numA.size())
        return;

    if (ui->spinReset->value() == -1)
        numA.reset();
    else
        numA.reset(ui->spinReset->value());
    showNumA();
}


void MainWindow::on_to_ullong_clicked()
{
    ui->labelUll->setText(QString::number(numA.to_ullong()));
}


void MainWindow::on_notButton_clicked()
{
    numA = ~numA;
    //numA = (numA);
    showNumA();
}


void MainWindow::on_rndB_clicked()
{
    numB = Bitset(129);
    for (int i = 0; i < 129; i++)
        numB[i] = rnd() % 2;

    showNumB();
}


void MainWindow::on_addDigitB_clicked()
{
    numB = (Bitset(numB.size()+1, 0) | numB);
    numB[numB.size()-1] = ui->spinBoxB->value();

    showNumB();
}


void MainWindow::on_removeDigitB_clicked()
{
    if (numB.size() > 1)
        numB = (Bitset(numB.size()-1, 0) | numB);

    showNumB();
}


void MainWindow::on_andButton_clicked()
{
    numA &= numB;
    showNumA();
}


void MainWindow::on_orButton_clicked()
{
    numA |= numB;
    showNumA();
}


void MainWindow::on_xorButton_clicked()
{
    numA ^= numB;
    showNumA();
}

