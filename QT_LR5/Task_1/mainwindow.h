#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QKeyEvent>
#include <QLocale>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QTimer>
#include <QFileDialog>
#include <QTextCursor>
#include <QTextCharFormat>
#include <iostream>
#include <fstream>

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
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void keyPressEvent(QKeyEvent* event) override;
    //void keyReleaseEvent(QKeyEvent* event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    const int TEXT_SZ = 110;
    const int PROBABILITY_OF_SPACE = 4;
    const double TIMER_INTERVAL = 20;
    Ui::MainWindow *ui;

    QString cur_file;
    QString alphabet;
    QString textToWrite;
    QString writtenText;
    QTimer timer;

    QTextCursor cursor;

    QTextCharFormat format;

    double wrongPressed;
    double rightPressed;

    double prevWrongPressed;

    double rightWords;
    double wrongWords;


    double currentTime;
};
#endif // MAINWINDOW_H
