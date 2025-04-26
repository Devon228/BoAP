#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QTableWidget>
#include <random>
#include "bitset.h"

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
    void showNumA();
    void showNumB();

    void on_rnd_clicked();

    void on_addDigit_clicked();

    void on_removeDigit_clicked();

    void on_count_clicked();

    void on_flip_clicked();

    void on_set_clicked();

    void on_reset_clicked();

    void on_to_ullong_clicked();

    void on_notButton_clicked();

    void on_rndB_clicked();

    void on_addDigitB_clicked();

    void on_removeDigitB_clicked();

    void on_andButton_clicked();

    void on_orButton_clicked();

    void on_xorButton_clicked();

private:
    Ui::MainWindow *ui;
    Bitset numA, numB;
};
#endif // MAINWINDOW_H
