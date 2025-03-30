#include "askperswidget.h"

AskPersWidget::AskPersWidget(QWidget *parent) : QWidget{parent}
{
    name_e = new QLineEdit();
    bdate_e = new QDateEdit();
    job_e = new QLineEdit();
    wage_e = new QSpinBox();
    exp_e = new QSpinBox();
    is_he_e = new QComboBox();

    name_e->setMaxLength(500);
    job_e->setMaxLength(500);
    wage_e->setRange(0, 1000000);
    exp_e->setRange(0, 120);
    is_he_e->addItem("Нет"); is_he_e->addItem("Да");

    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(tr("ФИО: "), name_e);
    layout->addRow(tr("Дата рождения: "), bdate_e);
    layout->addRow(tr("Желаемая должность: "), job_e);
    layout->addRow(tr("Наличие высшего образования: "), is_he_e);
    layout->addRow(tr("Желаемая з/п: "), wage_e);
    layout->addRow(tr("Опыт в должности: "),  exp_e);

    okButton = new QPushButton("Ок");
    layout->addRow(okButton);
}

AskPersWidget::~AskPersWidget()
{
    this->close();
}
