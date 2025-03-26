#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include "mygraphicsscene.h"
#include "rectangle.h"
#include "figure.h"
#include "npolygon.h"
#include "ellipse.h"

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
    void updateScene();


private slots:
    void updateLabelText(QString& p, QString& a, QString& xc, QString& yc);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    MyGraphicsScene* scene;
    QTimer *upd_timer;

};
#endif // MAINWINDOW_H
