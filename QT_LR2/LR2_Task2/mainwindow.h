#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QSignalBlocker>
#include <QHeaderView>
#include <QTimer>
#include <vector>
#include <algorithm>

#include "vacancy.h"
#include "person.h"
#include "askvacwidget.h"
#include "askperswidget.h"
#include "filework.h"

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
    void on_addButton_clicked();
    void on_okAddButton_clicked();

    void on_delButton_clicked();

    void on_changeButton_clicked();
    void on_okChButton_clicked();

    void on_saveVacButton_clicked();

    void on_openButton_clicked();

    void on_sortButton_clicked();
    void on_okSortButton_clicked();


    void on_addButton_2_clicked();
    void on_okAddButton_2_clicked();

    void on_delButton_2_clicked();

    void on_changeButton_2_clicked();
    void on_okChButton_2_clicked();

    void on_saveButton_2_clicked();

    void on_openButton_2_clicked();

    void on_sortButton_2_clicked();

    void on_okSortButton_2_clicked();


    inline bool is_match (int i, int j);
    void on_deficitButton_clicked();

    void on_deficitButton_2_clicked();

    void on_findButton_clicked();

private:
    void disableInterface();
    void enableInterface();
    void updateInterface();
    void changeRowVac (int i);
    void changeRowPers (int i);

    Ui::MainWindow *ui;
    std::vector <Vacancy> list_vac;
    int list_vac_sz;
    AskVacWidget* addw;

    std::vector <Person> list_pers;
    int list_pers_sz;
    AskPersWidget* addwp;

    FileWork* file;

    QWidget* sortw; //tak sebe idea
    QComboBox* choice;
    QWidget* sortwp;
    QComboBox* choicep;

    QWidget *w_deficit, *w_find;

    QTimer* upd_timer;

};
#endif // MAINWINDOW_H
