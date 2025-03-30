#include "askvacwidget.h"

AskVacWidget::AskVacWidget(QWidget *parent) : QWidget{parent}
{
    name_e = new QLineEdit();
    job_e = new QLineEdit();
    wage_e = new QSpinBox();
    vacation_e = new QSpinBox();
    min_age_e = new QSpinBox();
    max_age_e = new QSpinBox();
    exp_e = new QSpinBox();
    req_he_e = new QComboBox();

    name_e->setMaxLength(500);
    job_e->setMaxLength(500);
    wage_e->setRange(0, 1000000);
    vacation_e->setRange(0, 366);
    min_age_e->setRange(0, 120);
    max_age_e->setRange(0, 120);
    exp_e->setRange(0, 120);
    req_he_e->addItem("Нет"); req_he_e->addItem("Да");

    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(tr("Название компании: "), name_e);
    layout->addRow(tr("Должность: "), job_e);
    layout->addRow(tr("Оклад: "), wage_e);
    layout->addRow(tr("Длина отпуска: "), vacation_e);
    layout->addRow(tr("Наличие высшего образования: "), req_he_e);
    layout->addRow(tr("Минимальный возраст: "), min_age_e);
    layout->addRow(tr("Максимальный возраст: "), max_age_e);
    layout->addRow(tr("Минимальный опыт: "),  exp_e);

    okButton = new QPushButton("Ок");
    layout->addRow(okButton);
}
AskVacWidget::~AskVacWidget()
{
    this->close();
}
