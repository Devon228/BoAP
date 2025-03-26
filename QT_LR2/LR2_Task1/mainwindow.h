#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QSpinBox>
#include <QDebug>
#include <ctime>
#include "date.h"
#include "filework.h"
//#include <iostream>


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
        void on_fileSelectButton_clicked();

        void on_prevButton_clicked();

        void on_isLeapButton_clicked();

        void on_weekButton_clicked();

        void on_bdayButton_clicked();

        void on_spinDay_valueChanged(int arg1);

        void on_spinMonth_valueChanged(int arg1);

        void on_spinYear_valueChanged(int arg1);

        void on_editButton_clicked();

        void on_buttonData2_clicked();

        void on_addButton_clicked();

        void on_spinDay_2_valueChanged(int arg1);

        void on_spinMonth_2_valueChanged(int arg1);

        void on_spinYear_2_valueChanged(int arg1);

    private:
        //void readCurrentFile();
        void createTable();
        void changeRow(int i);

        Ui::MainWindow *ui;
        FileWork current_file;
        Date bday, today, newday;
        Date* date_list;
        int list_sz;

        QWidget *qw;
        QSpinBox *spinDay_2, *spinMonth_2, *spinYear_2;
};
#endif // MAINWINDOW_H
