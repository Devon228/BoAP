#include "mainwindow.h"
#include "ui_mainwindow.h"

std::mt19937 rnd(228);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    std::cout << "Введите размер:\n";
    std::cin >> n;
    std::vector <double> a(n);
    std::vector <double> m(0);
    std::cout << "Введите массив:\n";
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    */

    ui->spinBox->setMinimum(-1000000000);
    ui->spinBox->setMaximum(1000000000);

    ui->tableWidget->insertColumn(0);


    //createMVect(a, m);

    //for (auto i : m)
        //std::cout << i << " ";
}

void MainWindow::createMVect (std::vector <double> a)
{
    m.clear();
    for (int i = 0; i + 2 < a.size(); i += 3)
    {
        std::sort(a.begin() + i, a.begin() + i + 3);
        m.push_back(a[i+1]);
    }
    if (a.size() % 3 == 1)
        m.push_back(a[a.size()-1]);
    if (a.size() % 3 == 2)
        m.push_back((a[a.size()-2] + a[a.size()-1]) / 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    a.push_back(ui->spinBox->value());
    createMVect(a);
    addItem(a.back());
}

void MainWindow::addItem(double el)
{
    if (a.size() > 1)
        ui->tableWidget->insertColumn(a.size()-1);
    ui->tableWidget->setItem(0, a.size()-1,new QTableWidgetItem(QString::number(el)));
    ui->tableWidget->setItem(1, m.size() - 1, new QTableWidgetItem(QString::number(m.back())));
}

void MainWindow::on_delButton_clicked()
{
    if (a.empty())
        return;

    a.pop_back();
    createMVect(a);
    delItem();
}

void MainWindow::delItem ()
{
    if (a.size() > 0)
        ui->tableWidget->removeColumn(a.size());
    else
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem());
    if (a.size() % 3 == 0)
        ui->tableWidget->setItem(1, m.size(), new QTableWidgetItem());
    else
        ui->tableWidget->setItem(1, m.size() - 1, new QTableWidgetItem(QString::number(m.back())));
}


void MainWindow::on_randomButton_clicked()
{
    while (!a.empty())
    {
        a.pop_back();
        delItem();
    }

    for (int i = 0; i < 11; i++)
    {
        a.push_back(rnd() % 1000);
        createMVect(a);
        addItem(a.back());
    }
}

