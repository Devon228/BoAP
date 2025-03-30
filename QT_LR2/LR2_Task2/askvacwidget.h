#ifndef ASKVACWIDGET_H
#define ASKVACWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include <QPushButton>


class AskVacWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AskVacWidget(QWidget *parent = nullptr);
    ~AskVacWidget();

    QLineEdit *name_e, *job_e;
    QSpinBox *wage_e, *vacation_e, *min_age_e, *max_age_e, *exp_e;
    QComboBox *req_he_e;
    QPushButton* okButton;
};

#endif // ASKVACWIDGET_H
