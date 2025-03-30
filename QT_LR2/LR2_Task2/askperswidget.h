#ifndef ASKPERSWIDGET_H
#define ASKPERSWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include <QDateEdit>
#include <QPushButton>

class AskPersWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AskPersWidget(QWidget *parent = nullptr);
    ~AskPersWidget();

    QLineEdit *name_e, *job_e;
    QSpinBox *wage_e, *exp_e;
    QComboBox *is_he_e;
    QDateEdit *bdate_e;
    QPushButton* okButton;

signals:
};

#endif // ASKPERSWIDGET_H
