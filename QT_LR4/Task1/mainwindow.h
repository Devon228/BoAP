#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QTableWidget>
#include <iostream>
#include <random>
#include <vector>
#include "sort.h"
typedef long long ll;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void on_addButton_clicked();

        void on_delButton_clicked();

        void on_randomButton_clicked();

        void on_binsButton_clicked();

        void on_sortButton_clicked();

    private:
        Ui::MainWindow *ui;
        std::vector <ll> arr1, arr2, arr3, arr4;
};
#endif // MAINWINDOW_H
