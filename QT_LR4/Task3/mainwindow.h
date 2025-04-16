#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSpinBox>
#include <QTableWidget>
#include <vector>
#include <iostream>
#include <random>

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
    void createMVect (std::vector <double> a);
    void addItem(double el);
    void delItem();

private slots:
    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_randomButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector <double> a;
    std::vector <double> m;
};
#endif // MAINWINDOW_H
