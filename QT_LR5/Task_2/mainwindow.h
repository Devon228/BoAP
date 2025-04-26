#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "mystring.h"

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
    void on_pushButton_2_clicked();

    void on_strcatB_clicked();

    void on_strcmpB_clicked();

    void on_strlen_clicked();

    void on_strncpyB_clicked();

    void on_strncatB_clicked();

    void on_strncmpB_clicked();

    void on_memcpyB_clicked();

    void on_memcmpB_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
