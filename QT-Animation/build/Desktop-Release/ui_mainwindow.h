/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widget;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *rightButton;
    QPushButton *leftButton;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *removeButton;
    QToolButton *updateButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1080, 720);
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(310, 20, 731, 581));
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 160, 281, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        rightButton = new QPushButton(gridLayoutWidget);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));

        gridLayout->addWidget(rightButton, 1, 2, 1, 1);

        leftButton = new QPushButton(gridLayoutWidget);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));

        gridLayout->addWidget(leftButton, 1, 0, 1, 1);

        upButton = new QPushButton(gridLayoutWidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        gridLayout->addWidget(upButton, 0, 1, 1, 1);

        downButton = new QPushButton(gridLayoutWidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));

        gridLayout->addWidget(downButton, 2, 1, 1, 1);

        removeButton = new QPushButton(gridLayoutWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        gridLayout->addWidget(removeButton, 1, 1, 1, 1);

        updateButton = new QToolButton(widget);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(90, 390, 121, 91));
        MainWindow->setCentralWidget(widget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        downButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\277\320\275\321\203\321\202\321\214", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "\320\267\320\260\320\275\320\276\320\262\320\276", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\264\321\203\321\210\320\275\321\213\320\271 \321\210\320\260\321\200\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
