#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //растяжение ласт колонку таблицы
    ui->tableWidget->setShowGrid(true); // включаем сетку
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //no user simple edit
    list_vac_sz = 0;

    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true); //растяжение ласт колонку таблицы
    ui->tableWidget_2->setShowGrid(true); // включаем сетку
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //no user simple edit
    list_pers_sz = 0;


    file = new FileWork();
    if (file->readVFile(list_vac, list_vac_sz) == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Не удалось прочитать файл из-за неправильного формата файла вакансий");
    }
    for (int i = 0; i < list_vac_sz; i++)
    {
        ui->tableWidget->insertRow(i);
        changeRowVac(i);
    }
    ui->tableWidget->resizeColumnsToContents();
    if (file->readPFile(list_pers, list_pers_sz) == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Не удалось прочитать файл из-за неправильного формата файла вакансий");
    }
    for (int i = 0; i < list_pers_sz; i++)
    {
        ui->tableWidget_2->insertRow(i);
        changeRowPers(i);
    }
    ui->tableWidget_2->resizeColumnsToContents();



    //this is mb not normal mb best option is catch some signals
    upd_timer = new QTimer();
    connect(upd_timer, &QTimer::timeout, this, &MainWindow::updateInterface);
    upd_timer->start(50);
    addw = nullptr;
    addwp = nullptr;
    sortw = nullptr;
    sortwp = nullptr;
    w_deficit = nullptr;
    w_find = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::disableInterface()
{
    this->setDisabled(true);
}
void MainWindow::enableInterface()
{
    this->setDisabled(false);
}
void MainWindow::updateInterface()
{
    if ((addw == nullptr || !addw->isVisible())
        && (addwp == nullptr || !addwp->isVisible())
        && (sortw == nullptr || !sortw->isVisible())
        && (sortwp == nullptr || !sortwp->isVisible())
        && (w_deficit == nullptr || !w_deficit->isVisible())
        && (w_find == nullptr || !w_find->isVisible()))
        enableInterface();
}


void MainWindow::on_addButton_clicked()
{
    //blocksignals

    addw = new AskVacWidget();
    //QLabel *name_l = new QLabel("Название компании: "), *job_l = new QLabel("Должность: "), *wage_l = new QLabel("Уровень зарплаты: "), *vacation_l, *req_he_l, *min_age_l, *max_age_l, *experience_l;
    /*QLineEdit *name_e = new QLineEdit(), *job_e = new QLineEdit();
    QSpinBox *wage_e = new QSpinBox(), *vacation_e = new QSpinBox(), *min_age_e = new QSpinBox(), *max_age_e = new QSpinBox(), *exp_e = new QSpinBox();
    QComboBox *req_he_e = new QComboBox(); req_he_e->addItem("Да"); req_he_e->addItem("Нет");*/
    connect(addw->okButton, &QPushButton::clicked, this, &MainWindow::on_okAddButton_clicked);
    addw->show();
    disableInterface();

    //disable another
}

void MainWindow::on_okAddButton_clicked()
{
    if (addw->name_e->text() != "" && addw->job_e->text() != "")
    {
        addw->close();
        Vacancy newVac(addw->name_e->text().toStdString(), addw->job_e->text().toStdString(), addw->wage_e->value(), addw->vacation_e->value(), addw->req_he_e->currentIndex(), addw->min_age_e->value(), addw->max_age_e->value(), addw->exp_e->value());
        list_vac.push_back(newVac);
        ui->tableWidget->insertRow(list_vac_sz);
        changeRowVac(list_vac_sz);
        list_vac_sz++;
    }

    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::changeRowVac (int i)
{
    QString cur = QString(QString::fromStdString(list_vac[i].getName()));
    ui->tableWidget->setItem(i,0, new QTableWidgetItem(cur));
    cur = QString(QString::fromStdString(list_vac[i].getJob()));
    ui->tableWidget->setItem(i,1, new QTableWidgetItem(cur));
    cur = QString(QString::number(list_vac[i].getWage()));
    ui->tableWidget->setItem(i,2, new QTableWidgetItem(cur));
    cur = QString(QString::number(list_vac[i].getVac()));
    ui->tableWidget->setItem(i,3, new QTableWidgetItem(cur));
    cur = QString((list_vac[i].getReqHE() ? "Да" : "Нет"));
    ui->tableWidget->setItem(i,4, new QTableWidgetItem(cur));
    cur = QString(QString::number(list_vac[i].getMinAge())+"-"+QString::number(list_vac[i].getMaxAge()));
    ui->tableWidget->setItem(i,5, new QTableWidgetItem(cur));
    cur = QString(QString::number(list_vac[i].getExp()));
    ui->tableWidget->setItem(i,6, new QTableWidgetItem(cur));

}


void MainWindow::on_delButton_clicked()
{
    //blocksignals

    int index = ui->tableWidget->selectionModel()->currentIndex().row();

    if (index == -1)
        return;

    list_vac.erase(list_vac.begin() + index);
    list_vac_sz--;

    ui->tableWidget->removeRow(index);

    ui->tableWidget->resizeColumnsToContents();
}


void MainWindow::on_changeButton_clicked()
{
    //block signals

    int index = ui->tableWidget->selectionModel()->currentIndex().row();

    if (index == -1)
        return;

    addw = new AskVacWidget();
    //QLabel *name_l = new QLabel("Название компании: "), *job_l = new QLabel("Должность: "), *wage_l = new QLabel("Уровень зарплаты: "), *vacation_l, *req_he_l, *min_age_l, *max_age_l, *experience_l;
    /*QLineEdit *name_e = new QLineEdit(), *job_e = new QLineEdit();
    QSpinBox *wage_e = new QSpinBox(), *vacation_e = new QSpinBox(), *min_age_e = new QSpinBox(), *max_age_e = new QSpinBox(), *exp_e = new QSpinBox();
    QComboBox *req_he_e = new QComboBox(); req_he_e->addItem("Да"); req_he_e->addItem("Нет");*/
    connect(addw->okButton, &QPushButton::clicked, this, &MainWindow::on_okChButton_clicked);
    addw->show();
    disableInterface();
    //disable another
}

void MainWindow::on_okChButton_clicked()
{
    if (addw->name_e->text() != "" && addw->job_e->text() != "")
    {
        addw->close();
        Vacancy newVac(addw->name_e->text().toStdString(), addw->job_e->text().toStdString(), addw->wage_e->value(), addw->vacation_e->value(), addw->req_he_e->currentIndex(), addw->min_age_e->value(), addw->max_age_e->value(), addw->exp_e->value());
        int index = ui->tableWidget->selectionModel()->currentIndex().row();
        list_vac[index] = newVac;
        changeRowVac(index);
    }

    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_saveVacButton_clicked()
{
    file->saveVFile(list_vac, list_vac_sz);
    QMessageBox::information(this, "Сохранение файла", "Сохранено"); //home/dimas/Документы/LR2_/LR2_Task2/vac.txt
}


void MainWindow::on_openButton_clicked()
{
    //blocksignals

    file->setVFile(QFileDialog::getOpenFileName(this, tr("Open Txt File"), "/home/dimas/Документы/LR2_/LR2_Task2/", tr("Text File (*.txt)")));

    if (file->readVFile(list_vac, list_vac_sz) == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Не удалось прочитать файл из-за неправильного формата файла вакансий. Открыт vac_normal.txt");
        file->setVFile("/home/dimas/Документы/LR2_/LR2_Task2/vac_normal.txt");
        file->clearVFile();
        file->readVFile(list_vac, list_vac_sz);
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for (int i = 0; i < list_vac_sz; i++)
    {
        ui->tableWidget->insertRow(i);
        changeRowVac(i);
    }

    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_sortButton_clicked()
{
    sortw = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(sortw);
    choice = new QComboBox();
    choice->addItem("Компания");
    choice->addItem("Должность");
    choice->addItem("Оклад");
    choice->addItem("Длительность отпуска");
    choice->addItem("Нужность высшего");
    choice->addItem("Минимальный возраст");
    choice->addItem("Максимальный возраст");
    choice->addItem("Необходимый опыт");
    layout->addWidget(choice);

    QPushButton* okButton = new QPushButton("Ок");
    connect(okButton, &QPushButton::clicked, this, &MainWindow::on_okSortButton_clicked);
    layout->addWidget(okButton);

    sortw->show();
    disableInterface();

    //disable another ui
}

void MainWindow::on_okSortButton_clicked()
{
    sortw->close();

    int crit = choice->currentIndex();

    switch (crit)
    {
    case 0:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getName() < b.getName();});
        break;
    }
    case 1:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getJob() < b.getJob();});
        break;
    }
    case 2:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getWage() < b.getWage();});
        break;
    }
    case 3:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getVac() < b.getVac();});
        break;
    }
    case 4:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getReqHE() < b.getReqHE();});
        break;
    }
    case 5:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getMinAge() < b.getMinAge();});
        break;
    }
    case 6:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getMaxAge() < b.getMaxAge();});
        break;
    }
    case 7:
    {
        std::sort(list_vac.begin(), list_vac.end(), [](Vacancy& a, Vacancy& b) {return a.getExp() < b.getExp();});
        break;
    }
    }

    for (int i  = 0; i < list_vac_sz; i++)
        changeRowVac(i);
}



void MainWindow::on_addButton_2_clicked()
{
    //blocksignals

    addwp = new AskPersWidget();
    //QLabel *name_l = new QLabel("Название компании: "), *job_l = new QLabel("Должность: "), *wage_l = new QLabel("Уровень зарплаты: "), *vacation_l, *req_he_l, *min_age_l, *max_age_l, *experience_l;
    /*QLineEdit *name_e = new QLineEdit(), *job_e = new QLineEdit();
    QSpinBox *wage_e = new QSpinBox(), *vacation_e = new QSpinBox(), *min_age_e = new QSpinBox(), *max_age_e = new QSpinBox(), *exp_e = new QSpinBox();
    QComboBox *req_he_e = new QComboBox(); req_he_e->addItem("Да"); req_he_e->addItem("Нет");*/
    connect(addwp->okButton, &QPushButton::clicked, this, &MainWindow::on_okAddButton_2_clicked);
    addwp->show();
    disableInterface();


    //disable another
}

void MainWindow::on_okAddButton_2_clicked()
{
    if (addwp->name_e->text() != "" && addwp->job_e->text() != "")
    {
        addwp->close();
        Person newPers(addwp->name_e->text().toStdString(), addwp->bdate_e->date(), addwp->job_e->text().toStdString(), addwp->is_he_e->currentIndex(), addwp->wage_e->value(), addwp->exp_e->value());
        list_pers.push_back(newPers);

        ui->tableWidget_2->insertRow(list_pers_sz);
        changeRowPers(list_pers_sz);

        list_pers_sz++;
    }

    ui->tableWidget_2->resizeColumnsToContents();
}

void MainWindow::changeRowPers (int i)
{
    QString cur = QString(QString::fromStdString(list_pers[i].getName()));
    ui->tableWidget_2->setItem(i,0, new QTableWidgetItem(cur));
    cur = QString(list_pers[i].getBDate().toString("dd.MM.yyyy"));
    ui->tableWidget_2->setItem(i,1, new QTableWidgetItem(cur));
    cur = QString(QString::fromStdString(list_pers[i].getJob()));
    ui->tableWidget_2->setItem(i,2, new QTableWidgetItem(cur));
    cur = QString((list_pers[i].getHE() ? "Да" : "Нет"));
    ui->tableWidget_2->setItem(i,3, new QTableWidgetItem(cur));
    cur = QString(QString::number(list_pers[i].getWage()));
    ui->tableWidget_2->setItem(i,4, new QTableWidgetItem(cur));
    cur = QString(QString::number(list_pers[i].getExp()));
    ui->tableWidget_2->setItem(i,5, new QTableWidgetItem(cur));
}

void MainWindow::on_delButton_2_clicked()
{
    //blocksignals

    int index = ui->tableWidget_2->selectionModel()->currentIndex().row();

    if (index == -1)
        return;

    list_pers.erase(list_pers.begin() + index);
    list_pers_sz--;

    ui->tableWidget_2->removeRow(index);

    ui->tableWidget_2->resizeColumnsToContents();
}


void MainWindow::on_changeButton_2_clicked()
{
    //block signals

    int index = ui->tableWidget_2->selectionModel()->currentIndex().row();

    if (index == -1)
        return;

    addwp = new AskPersWidget();
    //QLabel *name_l = new QLabel("Название компании: "), *job_l = new QLabel("Должность: "), *wage_l = new QLabel("Уровень зарплаты: "), *vacation_l, *req_he_l, *min_age_l, *max_age_l, *experience_l;
    /*QLineEdit *name_e = new QLineEdit(), *job_e = new QLineEdit();
    QSpinBox *wage_e = new QSpinBox(), *vacation_e = new QSpinBox(), *min_age_e = new QSpinBox(), *max_age_e = new QSpinBox(), *exp_e = new QSpinBox();
    QComboBox *req_he_e = new QComboBox(); req_he_e->addItem("Да"); req_he_e->addItem("Нет");*/
    connect(addwp->okButton, &QPushButton::clicked, this, &MainWindow::on_okChButton_2_clicked);
    addwp->show();
    disableInterface();

    //disable another
}

void MainWindow::on_okChButton_2_clicked()
{
    if (addwp->name_e->text() != "" && addwp->job_e->text() != "")
    {
        addwp->close();
        Person newPers(addwp->name_e->text().toStdString(), addwp->bdate_e->date(), addwp->job_e->text().toStdString(), addwp->is_he_e->currentIndex(), addwp->wage_e->value(), addwp->exp_e->value());
        int index = ui->tableWidget_2->selectionModel()->currentIndex().row();
        list_pers[index] = newPers;
        changeRowPers(index);
    }

    ui->tableWidget_2->resizeColumnsToContents();
}

void MainWindow::on_saveButton_2_clicked()
{
    file->savePFile(list_pers, list_pers_sz);
    QMessageBox::information(this, "Сохранение файла", "Сохранено"); //  в /home/dimas/Документы/LR2_/LR2_Task2/pers.txt
}

void MainWindow::on_openButton_2_clicked()
{
    //blocksignals

    file->setPFile(QFileDialog::getOpenFileName(this, tr("Open Txt File"), "/home/dimas/Документы/LR2_/LR2_Task2/", tr("Text File (*.txt)")));

    if (file->readPFile(list_pers, list_pers_sz) == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Не удалось прочитать файл из-за неправильного формата файла кандидатов. Открыт pers_normal.txt");
        file->setPFile("/home/dimas/Документы/LR2_/LR2_Task2/pers_normal.txt");
        file->clearPFile();
        file->readPFile(list_pers, list_pers_sz);
    }

    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(0);
    for (int i = 0; i < list_pers_sz; i++)
    {
        ui->tableWidget_2->insertRow(i);
        changeRowPers(i);
    }

    ui->tableWidget_2->resizeColumnsToContents();
}

void MainWindow::on_sortButton_2_clicked()
{
    sortwp = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(sortwp);
    choicep = new QComboBox();
    choicep->addItem("ФИО");
    choicep->addItem("Дата рождения");
    choicep->addItem("Должность");
    choicep->addItem("Наличие высшего");
    choicep->addItem("Желаемая з/п");
    choicep->addItem("Опыт в должности");
    layout->addWidget(choicep);

    QPushButton* okButton = new QPushButton("Ок");
    connect(okButton, &QPushButton::clicked, this, &MainWindow::on_okSortButton_2_clicked);
    layout->addWidget(okButton);

    sortwp->show();
    disableInterface();

    //disable another ui
}


void MainWindow::on_okSortButton_2_clicked()
{
    sortwp->close();

    int crit = choicep->currentIndex();

    switch (crit)
    {
    case 0:
    {
        std::sort(list_pers.begin(), list_pers.end(), [](Person& a, Person& b) {return a.getName() < b.getName();});
        break;
    }
    case 1:
    {
        std::sort(list_pers.begin(), list_pers.end(), [](Person& a, Person& b) {return a.getBDate() < b.getBDate();});
        break;
    }
    case 2:
    {
        std::sort(list_pers.begin(), list_pers.end(), [](Person& a, Person& b) {return a.getJob() < b.getJob();});
        break;
    }
    case 3:
    {
        std::sort(list_pers.begin(), list_pers.end(), [](Person& a, Person& b) {return a.getHE() < b.getHE();});
        break;
    }
    case 4:
    {
        std::sort(list_pers.begin(), list_pers.end(), [](Person& a, Person& b) {return a.getWage() < b.getWage();});
        break;
    }
    case 5:
    {
        std::sort(list_pers.begin(), list_pers.end(), [](Person& a, Person& b) {return a.getExp() < b.getExp();});
        break;
    }
    }

    for (int i  = 0; i < list_pers_sz; i++)
        changeRowPers(i);
}

bool MainWindow::is_match (int i, int j)
{
    if (i == 1 && j == 5)
    {
        qDebug() << (list_vac[i].getJob() == list_pers[j].getJob());
        qDebug() << (list_vac[i].getWage() >= list_pers[j].getWage());
        qDebug() << (list_vac[i].getReqHE() <= list_pers[j].getHE());
        qDebug() <<  (list_vac[i].getMinAge() <= list_pers[j].getAge() && list_pers[j].getAge() <= list_vac[i].getMaxAge());
        qDebug() << (list_vac[i].getExp() <= list_pers[j].getExp());
    }
    return (list_vac[i].getJob() == list_pers[j].getJob() && list_vac[i].getWage() >= list_pers[j].getWage() && list_vac[i].getReqHE() <= list_pers[j].getHE() && list_vac[i].getMinAge() <= list_pers[j].getAge() && list_pers[j].getAge() <= list_vac[i].getMaxAge() && list_vac[i].getExp() <= list_pers[j].getExp());
}

void MainWindow::on_deficitButton_clicked()
{
    w_deficit = new QWidget();
    w_deficit->setWindowTitle("Вакансии без подходящих кандидатов");

    QTableWidget* table_deficit = new QTableWidget(0, 7);
    table_deficit->horizontalHeader()->setStretchLastSection(true); //растяжение ласт колонку таблицы
    table_deficit->setShowGrid(true); // включаем сетку
    table_deficit->setEditTriggers(QAbstractItemView::NoEditTriggers); //no user simple edit
    table_deficit->setHorizontalHeaderLabels({"Компания", "Должность", "Оклад", "Длительность отпуска", "Нужно высшее?", "Возрастной диапазон", "Требуемый опыт"});

    QVBoxLayout* layout = new QVBoxLayout(w_deficit);
    layout->addWidget(table_deficit);

    int num_deficit = 0;

    for (int i = 0; i < list_vac_sz; i++)
    {
        bool found = 0;
        for (int j = 0; j < list_pers_sz; j++)
        {
            if (is_match(i, j))
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            table_deficit->insertRow(num_deficit);

            QString cur = QString(QString::fromStdString(list_vac[i].getName()));
            table_deficit->setItem(num_deficit,0, new QTableWidgetItem(cur));
            cur = QString(QString::fromStdString(list_vac[i].getJob()));
            table_deficit->setItem(num_deficit,1, new QTableWidgetItem(cur));
            cur = QString(QString::number(list_vac[i].getWage()));
            table_deficit->setItem(num_deficit,2, new QTableWidgetItem(cur));
            cur = QString(QString::number(list_vac[i].getVac()));
            table_deficit->setItem(num_deficit,3, new QTableWidgetItem(cur));
            cur = QString((list_vac[i].getReqHE() ? "Да" : "Нет"));
            table_deficit->setItem(num_deficit,4, new QTableWidgetItem(cur));
            cur = QString(QString::number(list_vac[i].getMinAge())+"-"+QString::number(list_vac[i].getMaxAge()));
            table_deficit->setItem(num_deficit,5, new QTableWidgetItem(cur));
            cur = QString(QString::number(list_vac[i].getExp()));
            table_deficit->setItem(num_deficit,6, new QTableWidgetItem(cur));

            num_deficit++;
        }
    }
    table_deficit->resizeColumnsToContents();

    w_deficit->resize(850, 425);
    w_deficit->show();
    disableInterface();
}


void MainWindow::on_deficitButton_2_clicked()
{
    w_deficit = new QWidget();
    w_deficit->setWindowTitle("Кандидаты без подходящих им вакансий");

    QTableWidget* table_deficit = new QTableWidget(0, 6);
    table_deficit->horizontalHeader()->setStretchLastSection(true); //растяжение ласт колонку таблицы
    table_deficit->setShowGrid(true); // включаем сетку
    table_deficit->setEditTriggers(QAbstractItemView::NoEditTriggers); //no user simple edit
    table_deficit->setHorizontalHeaderLabels({"ФИО", "Дата рождения", "Должность", "Наличие высшего", "Желаемая з/п", "Опыт в должности"});

    QVBoxLayout* layout = new QVBoxLayout(w_deficit);
    layout->addWidget(table_deficit);

    int num_deficit = 0;

    for (int i = 0; i < list_pers_sz; i++)
    {
        bool found = 0;
        for (int j = 0; j < list_vac_sz; j++)
        {
            if (is_match(j, i))
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            table_deficit->insertRow(num_deficit);

            QString cur = QString(QString::fromStdString(list_pers[i].getName()));
            table_deficit->setItem(num_deficit,0, new QTableWidgetItem(cur));
            cur = QString(list_pers[i].getBDate().toString("dd.MM.yyyy"));
            table_deficit->setItem(num_deficit,1, new QTableWidgetItem(cur));
            cur = QString(QString::fromStdString(list_pers[i].getJob()));
            table_deficit->setItem(num_deficit,2, new QTableWidgetItem(cur));
            cur = QString((list_pers[i].getHE() ? "Да" : "Нет"));
            table_deficit->setItem(num_deficit,3, new QTableWidgetItem(cur));
            cur = QString(QString::number(list_pers[i].getWage()));
            table_deficit->setItem(num_deficit,4, new QTableWidgetItem(cur));
            cur = QString(QString::number(list_pers[i].getExp()));
            table_deficit->setItem(num_deficit,5, new QTableWidgetItem(cur));

            num_deficit++;
        }
    }
    table_deficit->resizeColumnsToContents();

    w_deficit->resize(850, 425);
    w_deficit->show();
    disableInterface();
}


void MainWindow::on_findButton_clicked()
{
    w_find = new QWidget();
    w_find->setWindowTitle("Подбор кандидатов");

    QTableWidget* table_find = new QTableWidget(list_vac_sz, list_pers_sz);
    //table_deficit->horizontalHeader()->setStretchLastSection(true); //растяжение ласт колонку таблицы
    table_find->setShowGrid(true); // включаем сетку
    table_find->setEditTriggers(QAbstractItemView::NoEditTriggers); //no user simple edit
    //table_deficit->setHorizontalHeaderLabels({"ФИО", "Дата рождения", "Должность", "Наличие высшего", "Желаемая з/п", "Опыт"});

    QVBoxLayout* layout = new QVBoxLayout(w_find);
    layout->addWidget(table_find);

    table_find->setHorizontalHeaderItem(0, new QTableWidgetItem("Кандидаты\nВакансии"));
    for (int i = 0; i < list_vac_sz; i++)
    {
        table_find->setHorizontalHeaderItem(i, new QTableWidgetItem("Вакансия " + QString::number(i)));
        for (int j = 0; j < list_pers_sz; j++)
        {
            if (is_match(i, j))
            {
                table_find->setItem(i, j, new QTableWidgetItem("+"));
            }
            else
            {
                table_find->setItem(i, j, new QTableWidgetItem("-"));
            }
        }
    }

    for (int i = 0; i < list_vac_sz; i++)
        table_find->setVerticalHeaderItem(i, new QTableWidgetItem("Вакансия " + QString::number(i+1)));
    for (int j = 0; j < list_pers_sz; j++)
        table_find->setHorizontalHeaderItem(j, new QTableWidgetItem("Кандидат " + QString::number(j+1)));
    table_find->resizeColumnsToContents();

    w_find->resize(700, 300);
    w_find->show();
    disableInterface();
}

