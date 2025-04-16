#include "mainwindow.h"
#include "ui_mainwindow.h"

std::mt19937 rnd(228);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(nullptr);
    ui->setupUi(this);

    ui->spinBox->setMinimum(-1000000000);
    ui->spinBox->setMaximum(1000000000);
    ui->spinBox_2->setMinimum(-1000000000);
    ui->spinBox_2->setMaximum(1000000000);

    int n = 1e4;
    arr1.resize(n);
    arr2.resize(n);
    arr3.resize(n);
    arr4.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr1[i] = n / 2 - i * 2 + 218;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(Sort::HeapSort(n, arr1)) + QString("s")));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(QString::number(Sort::QuickSort(n, arr2)) + QString("s")));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem(QString::number(Sort::MergeSort(n, arr3)) + QString("s")));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem(QString::number(Sort::InterpolationSort(n, arr4, 0, ui->tableWidget_2)) + QString("s")));
    ui->tableWidget->resizeColumnsToContents();
    //std::cout << "Время работы на 1e6 элементах:\n" << "HeapSort: " << Sort::HeapSort(n, arr1) << "\nQuickSort: " << Sort::QuickSort(n, arr2) << "\nMergeSort: " << Sort::MergeSort(n, arr3) << "\nInterpolationSort:" << Sort::InterpolationSort(n, arr4, 0) << "\n";
    for (int i = 1; i < n; i++)
        if (arr4[i-1] > arr4[i])
            return;

    arr1.clear();
    arr2.clear();
    arr3.clear();
    arr4.clear();

    /*
    std::cout << "Введите размер массива:\n";
    std::cin >> n;
    arr1 = new ll[n];
    arr2 = new ll[n];
    arr3 = new ll[n];
    arr4 = new ll[n];
    std::cout << "Введите массив:\n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr1[i];
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

    std::cout << "Время работы на " << n << " элементах:\n" << "HeapSort: " << Sort::HeapSort(n, arr1) << " QuickSort: " << Sort::QuickSort(n, arr2) << " MergeSort: " << Sort::MergeSort(n, arr3) << "\nInterpolationSort:\n" << Sort::InterpolationSort(n, arr4, 1) << "\n";
    std::cout << "Итоговый массив:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr1[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << arr2[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << arr3[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << arr4[i] << " ";
    std::cout << "\n";

    std::cout << "Введите элемент для поиска:\n";
    ll el;
    std::cin >> el;
    int ind = Sort::BinSearch(n, arr1, el);
    std::cout << "Индекс: " << ind << "\n";
    if (ind != -1 && arr1[ind] > 0)
        std::cout << "Индекс найденного элемента в степени длинны массива по модулю числа: " << Sort::BinPow(ind, n, arr1[ind]) << "\n";

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    arr1.push_back(ui->spinBox->value());
    arr2.push_back(ui->spinBox->value());
    arr3.push_back(ui->spinBox->value());
    arr4.push_back(ui->spinBox->value());

    ui->tableWidget->insertColumn(arr1.size()-1+2);
    ui->tableWidget->setHorizontalHeaderItem(arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.size())));
    ui->tableWidget->setItem(0, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
    ui->tableWidget->setItem(1, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
    ui->tableWidget->setItem(2, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr2.back())));
    ui->tableWidget->setItem(3, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr3.back())));
    ui->tableWidget->setItem(4, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr4.back())));
}


void MainWindow::on_delButton_clicked()
{
    if (arr1.empty())
        return;

    for (int i = 0; i < arr1.size(); i++)
        ui->tableWidget->setItem(0, i+2, new QTableWidgetItem(QString::number(arr1[i])));
    arr1.pop_back();
    arr2.pop_back();
    arr3.pop_back();
    arr4.pop_back();
    ui->tableWidget->removeColumn(arr1.size()+2);
}


void MainWindow::on_randomButton_clicked()
{
    while (!arr1.empty())
    {
        arr1.pop_back();
        arr2.pop_back();
        arr3.pop_back();
        arr4.pop_back();
        ui->tableWidget->removeColumn(arr1.size()+2);
    }

    for (int i = 0; i < 11; i++)
    {
        arr1.push_back(rnd() % 1000);
        arr2.push_back(arr1.back());
        arr3.push_back(arr1.back());
        arr4.push_back(arr1.back());
        ui->tableWidget->insertColumn(arr1.size()-1+2);
        ui->tableWidget->setHorizontalHeaderItem(arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.size())));
        ui->tableWidget->setItem(0, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
        ui->tableWidget->setItem(1, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
        ui->tableWidget->setItem(2, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
        ui->tableWidget->setItem(3, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
        ui->tableWidget->setItem(4, arr1.size()-1+2, new QTableWidgetItem(QString::number(arr1.back())));
    }
}


void MainWindow::on_binsButton_clicked()
{
    int ind = Sort::BinSearch(arr1.size(), arr1, ui->spinBox_2->value());
    ui->label_3->setText("Индекс: " + QString::number(ind));
    if (ind != -1 && arr1[ind] > 0)
        ui->label_4->setText("Индекс найденного элемента в степени длинны массива по модулю числа: " + QString::number(Sort::BinPow(ind, arr1.size(), arr1[ind])));
    else
        ui->label_4->setText("Индекс найденного элемента в степени длинны массива по модулю числа: " + QString("-"));
}


void MainWindow::on_sortButton_clicked()
{
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(Sort::HeapSort(arr1.size(), arr1)) + QString("s")));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(Sort::QuickSort(arr2.size(), arr2)) + QString("s")));
    ui->tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(Sort::MergeSort(arr3.size(), arr3)) + QString("s")));
    ui->tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number(Sort::InterpolationSort(arr4.size(), arr4, 1, ui->tableWidget_2)) + QString("s")));
    ui->tableWidget->resizeColumnsToContents();
    for (int j = 0; j < arr1.size(); j++)
    {
        ui->tableWidget->setItem(1, j+2, new QTableWidgetItem(QString::number(arr1[j])));
        ui->tableWidget->setItem(2, j+2, new QTableWidgetItem(QString::number(arr2[j])));
        ui->tableWidget->setItem(3, j+2, new QTableWidgetItem(QString::number(arr3[j])));
        ui->tableWidget->setItem(4, j+2, new QTableWidgetItem(QString::number(arr4[j])));
    }
}

