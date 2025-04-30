#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 1000);
    w = nullptr;


    Plant my_plant1{"Tobacco", 2, {1, 2}, 'G', 1, 100.5};
    Plant my_plant2;
    my_plant2.name[0] = 'T';
    my_plant2.name[1] = 'o';
    my_plant2.name[2] = 'b';
    my_plant2.name[3] = 'a';
    my_plant2.name[4] = 'c';
    my_plant2.name[5] = 'c';
    my_plant2.name[6] = 'o';
    my_plant2.num_leaves = 4;
    my_plant2.leave_area[0] = 1;
    my_plant2.leave_area[1] = 2;
    my_plant2.leave_area[2] = 4;
    my_plant2.leave_area[3] = 3;
    my_plant2.code_place = 'G';
    my_plant2.is_toxic = 1;
    my_plant2.length = 120.5;

    QString out1;
    constructOut(my_plant1, out1);
    QString out2;
    constructOut(my_plant2, out2);
    ui->textEdit->setText(out1 + "\n" + out2);

    Plant* my_plant1_ptr = &my_plant1;
    my_plant1_ptr->name[0] = 'P';
    my_plant1_ptr->name[1] = 't';
    my_plant1_ptr->name[2] = 'r';
    my_plant1_ptr->name[3] = 'e';
    my_plant1_ptr->num_leaves = 1;
    my_plant1_ptr->leave_area[0] = 5;
    my_plant1_ptr->code_place = 'B';
    my_plant1_ptr->is_toxic = 1;
    my_plant1_ptr->length = 10.533;
    QString out3;
    constructOut(my_plant1_ptr, out3);
    ui->textEdit_3->setText(out3);

    Plant& my_plant1_ref = my_plant1;
    my_plant1_ref.name[0] = 'R';
    my_plant1_ref.name[1] = 'e';
    my_plant1_ref.name[2] = 'f';
    my_plant1_ref.name[3] = 'a';
    my_plant1_ref.num_leaves = 4;
    my_plant1_ref.leave_area[0] = 1;
    my_plant1_ref.leave_area[1] = 2;
    my_plant1_ref.leave_area[2] = 4;
    my_plant1_ref.leave_area[3] = 3;
    my_plant1_ref.code_place = 'L';
    my_plant1_ref.is_toxic = 1;
    my_plant1_ref.length = 1.3;
    QString out4;
    constructOutRef(my_plant1_ref, out4);
    ui->textEdit_4->setText(out4);
}

void MainWindow::constructOut(Plant p, QString& out)
{
    out = QString(p.name) + " | " + QString::number(p.num_leaves) + " | ";
    for (int i = 0; i < p.num_leaves; i++)
        out += QString::number(p.leave_area[i]) + " ";
    out += " | ";
    out += p.code_place;
    out += " | ";
    out += QString::number(p.is_toxic);
    out += " | ";
    out += QString::number(p.length);
}
void MainWindow::constructOut(Plant* p, QString& out)
{
    out = QString(p->name) + " | " + QString::number(p->num_leaves) + " | ";
    for (int i = 0; i < p->num_leaves; i++)
        out += QString::number(p->leave_area[i]) + " ";
    out += " | ";
    out += p->code_place;
    out += " | ";
    out += QString::number(p->is_toxic);
    out += " | ";
    out += QString::number(p->length);
}
void MainWindow::constructOutRef(Plant& p, QString& out)
{
    out = QString(p.name) + " | " + QString::number(p.num_leaves) + " | ";
    for (int i = 0; i < p.num_leaves; i++)
        out += QString::number(p.leave_area[i]) + " ";
    out += " | ";
    out += p.code_place;
    out += " | ";
    out += QString::number(p.is_toxic);
    out += " | ";
    out += QString::number(p.length);
}


MainWindow::~MainWindow()
{
    qDebug() << "mw";
    delete ui;
    delete w;
}

void MainWindow::on_pushButton_clicked()
{
    w = new QWidget();
    w->resize(700, 200);
    w->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    QFormLayout *layout = new QFormLayout(w);


    QLineEdit *name_e = new QLineEdit();
    name_e->setMaxLength(50);
    name_e->setText("Coca");
    layout->addRow(tr("Название: "), name_e);

    QSpinBox *num_leaves_b = new QSpinBox();
    num_leaves_b->setRange(0, 100);
    layout->addRow(tr("Количество листьев: "), num_leaves_b);

    QLineEdit *code_place_e = new QLineEdit();
    code_place_e->setMaxLength(1);
    code_place_e->setText("L");
    layout->addRow(tr("Код места: например L лес, B болото, P поле, G луг:"), code_place_e);

    QSpinBox *is_toxic_b = new QSpinBox();
    is_toxic_b->setRange(0, 1);
    layout->addRow(tr("1 если растение ядовито, 0 если нет:"), is_toxic_b);

    QDoubleSpinBox *length_b = new QDoubleSpinBox();
    length_b->setRange(0, 1000);
    length_b->setSingleStep(0.001);
    length_b->setDecimals(3);
    layout->addRow(tr("Длина растения:"), length_b);

    QPushButton *ok = new QPushButton();
    ok->setText("OK");
    connect(ok, &QPushButton::clicked, this, [this, name_e, num_leaves_b, code_place_e, is_toxic_b, length_b, layout] ()
            {
        std::string name = name_e->text().toStdString();
        strcpy(user_plant.name, name.c_str());
        qDebug() << user_plant.name;

        user_plant.num_leaves = num_leaves_b->value();

        std::string code_place = code_place_e->text().toStdString();
        user_plant.code_place = code_place[0];

        user_plant.is_toxic =  is_toxic_b->value();

        user_plant.length = length_b->value();

        if (name != "" && code_place != "")
        {
            w->close();

            delete name_e;
            delete num_leaves_b;
            delete code_place_e;
            delete is_toxic_b;
            delete length_b;
            delete layout;

            readArr(0);
        }
            });
    layout->addRow(ok);


    w->show();
    this->setDisabled(true);
    //out in readArr
}

void MainWindow::readArr(int i)
{
    if (i == user_plant.num_leaves)
    {
        this->setDisabled(false);
        QString out;
        constructOut(user_plant, out);
        ui->textEdit_2->setText(out);
        return;
    }

    QWidget *arrw = new QWidget();
    arrw->resize(50, 50);
    arrw->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    QFormLayout *arrlayout = new QFormLayout(arrw);

    QSpinBox *arr_b = new QSpinBox();
    arr_b->setRange(0, 1000);
    std::string istr = std::to_string(i) + ":";
    char text[100] = "Площадь листа номер ";
    strcat(text, istr.c_str());
    arrlayout->addRow(tr(text), arr_b);

    QPushButton *arrok = new QPushButton();
    arrok->setText("OK");
    connect(arrok, &QPushButton::clicked, this, [this, i, arrw, arr_b, arrlayout] ()
            {
                user_plant.leave_area[i] = arr_b->value();
                delete arr_b;
                delete arrlayout;

                arrw->close();
                readArr(i+1);
            });
    arrlayout->addRow(arrok);
    arrw->show();




}

