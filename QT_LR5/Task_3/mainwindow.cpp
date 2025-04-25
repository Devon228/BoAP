#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Bitset a(8, 5);
    Bitset b(9, 257);
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
    a.set();
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    a &= b;
    std::cout << a << "\n" << a.to_ullong() << " " << a.to_ulong() << " " << a.count() << "\n" << a.any() << " " << a.all() << " " << a.none() << " " << a.size() << "\n" << a.test(7) << " " << a.test(0) << "\n";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
