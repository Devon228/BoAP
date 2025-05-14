#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTableWidget>
#include <QMessageBox>
#include <QSpinBox>
#include "AVLtree.h"

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
    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_findButton_clicked();

    void on_pushButton_clicked();

private:
    void updPreT();
    void updPostT();
    void updInT();

    Ui::MainWindow *ui;
    AVLtree tree = AVLtree();
};
#endif // MAINWINDOW_H
