#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , h(16), h2(64), h3(128), h4(2048)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen(Qt::black, 4);//Просто выбираем цвет для карандашика
    scene->addLine(-250,90,200,90,pen);//x
    scene->addLine(-180,-200,-180,200,pen);//y
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;


    for (int i = 0; i < 8; i++)
    {
        int ind = i % 26;
        char c = 'a' + ind;
        std::string s; s += c;
        h.insert(s);
        ind = (i + 16) % 26;
        c = 'a' + ind;
        s = ""; s += c;
        h.insert(s);
    }
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        std::string s; s += c;
        clock_t start = clock();
        h.find(s);
        clock_t finish = clock();

        sum1 += (double)(finish - start) / CLOCKS_PER_SEC;
    }
    sum1 /= 26;
    sum1 *= 1e7;


    for (int i = 0; i < 32; i++)
    {
        int ind = i % 26;
        char c = 'a' + ind;
        std::string s; s += c;
        h2.insert(s);
        ind = (i + 32) % 26;
        c = 'a' + ind;
        s = ""; s += c;
        h2.insert(s);
    }
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        std::string s; s += c;
        clock_t start = clock();
        h2.find(s);
        clock_t finish = clock();

        sum2 += (double)(finish - start) / CLOCKS_PER_SEC;
    }
    sum2 /= 26;
    sum2 *= 1e7;

    std::mt19937 mrnd(228);
    for (int i = 0; i < 128; i++)
    {
        int ind = mrnd() % 26;
        char c = 'a' + ind;
        int ind2 = mrnd() % 26;
        char c2 = 'a' + ind2;
        std::string s;
        s += c;
        s += c2;
        h3.insert(s);
    }
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        std::string s;
        for (int j = 0; j < 26; j++)
        {
            s = "";
            s += c;
            char c1 = 'a' + j;
            s += c1;

            clock_t start = clock();
            h3.find(s);
            clock_t finish = clock();

            sum3 += (double)(finish - start) / CLOCKS_PER_SEC;
        }
    }
    sum3 /= 26 * 26;
    sum3 *= 1e7;

    for (int i = 0; i < 2048; i++)
    {
        int ind = mrnd() % 26;
        char c = 'a' + ind;
        int ind2 = mrnd() % 26;
        char c2 = 'a' + ind2;
        std::string s;
        s += c;
        s += c2;
        h4.insert(s);
    }
    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        std::string s;
        for (int j = 0; j < 26; j++)
        {
            s = "";
            s += c;
            char c1 = 'a' + j;
            s += c1;

            clock_t start = clock();
            h4.find(s);
            clock_t finish = clock();

            sum4 += (double)(finish - start) / CLOCKS_PER_SEC;
        }
    }
    sum4 /= 26 * 26;
    sum4 *= 1e7;

    std::cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4;

    QPen pen2(Qt::red, 3);
    scene->addLine(-160,90.0-sum1,-100,90.0-sum2,pen2);
    scene->addLine(-100,90.0-sum2,0,90.0-sum3,pen2);
    scene->addLine(0,90.0-sum3,200,90.0-sum4,pen2);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
