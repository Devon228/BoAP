#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTableWidget>
#include <QMessageBox>
#include "TaskHastTable.h"

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

    void on_eraseButton_clicked();

    void on_findButton_clicked();

    void on_rndButton_clicked();

    void on_mxButton_clicked();

private:
    void upd();

    Ui::MainWindow *ui;
    TaskHashTable h;
};
#endif // MAINWINDOW_H
