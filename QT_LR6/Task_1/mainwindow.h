#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include "Plant.h"

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
    void on_pushButton_clicked();

private:
    void readArr(int i);
    void constructOut(Plant p, QString& out);
    void constructOut(Plant* p, QString& out);
    void constructOutRef(Plant& p, QString& out);
    Ui::MainWindow *ui;
    QWidget *w;
    Plant user_plant;
};
#endif // MAINWINDOW_H
