#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Iterator <int> it;
    //Iterator <int> it1;
    int a = 5;
    Vector <int> v(5, 5);
    std::cout << v.size() << std::endl;
    for (int i = 0; i < (int)v.size(); i++)
        std::cout << v[i] << " ";
    Vector <int> v1({3, 4, 5});
    Iterator <int> it = v1.begin();
    std::cout << *(it+1);

    std::cout << v.back() << "\n";
    v.assign(5, 4);
    v.resize(4);
    v.clear();
    v.push_back(123123);
    std::cout << v.back() << "\n";
    v.assign(5, 5);
    v.push_back(1); v.push_back(2);
    std::cout << *(v.end() - 1) << " " << *(v.end() - 2) << "\n";
    v.pop_back();
    std::cout << *(v.end() - 1) << " " << *(v.end() - 2) << "\n";

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
    v.swap(v1);
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << "\n";

    v.swap(v1);
    v.insert(v.cbegin(), 5, 3);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    std::cout << "\n";
    v.insert(v.cend(), 5, 3);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    v.erase(v.cbegin());
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    v.erase(v.cbegin()+2, v.cbegin()+7);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    v.erase(v.cbegin()+4, v.cend()-1);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
    //std::cout << (it == it1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
