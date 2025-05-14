#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTableWidget>
#include <QMessageBox>
#include "Deque.h"

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
    void on_pushBackButton_clicked();

    void on_pushFrontButton_clicked();

    void on_popBackButton_clicked();

    void on_popFrontButton_clicked();

    void on_clearButton_clicked();

    void on_sizeButton_clicked();

    void on_emptyButton_clicked();

    void on_iButton_clicked();

private:
    void updTable();

    Ui::MainWindow *ui;
    Deque <int> q;
};
#endif // MAINWINDOW_H
