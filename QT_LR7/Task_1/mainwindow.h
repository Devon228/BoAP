#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSpinBox>
#include <QPushButton>
#include <QTableWidget>

#include <random>
#include "queue.h"

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

    void on_pushButton_clicked();

    void on_szButton_clicked();

    void on_pushButton_real_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Queue <QPixmap> qimg;
    Queue<QPixmap>::Node *cur;
};
#endif // MAINWINDOW_H
