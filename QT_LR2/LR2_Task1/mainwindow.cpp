#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
    while (1)
    {
        int d, m, y;
        std::cin >> d >> m >> y;
        Date da(d, m ,y);
        std::cout << "next: " << da.NextDay().d << " " <<da.NextDay().m << " " << da.NextDay().y<< "\n";
        std::cout << "previous: " << da.PreviousDay().d << " " <<da.PreviousDay().m << " " << da.PreviousDay().y<< "\nbirthday: ";
        int d1, m1, y1;
        std::cin >> d1 >> m1 >> y1;
        Date bday(d1, m1, y1);
        std::cout << da.DaysTillYourBirthday(bday) << "\n";
    }
    */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fileNameLabel->setWordWrap(true); //перенос слов
    ui->fileNameLabel->setAlignment(Qt::AlignTop); //выравнивание
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //растяжение ласт колонку таблицы
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setShowGrid(true); // включаем сетку
    //ui->tableWidget->hideColumn(0); //скрыть 0 колонку
    //запретить выделение

    //ui->widgetAdd->hide();

    spinDay_2 = new QSpinBox();
    spinMonth_2 = new QSpinBox();
    spinYear_2 = new QSpinBox();
    ui->spinDay->setRange(1, 31); //depends on month
    ui->spinMonth->setRange(1, 12);
    ui->spinYear->setRange(1, 9999);
    spinDay_2->setRange(1, 31); //depends on month
    spinMonth_2->setRange(1, 12);
    spinYear_2->setRange(1, 9999);
    connect(spinDay_2, SIGNAL(valueChanged(int)), this, SLOT(on_spinDay_2_valueChanged(int)));
    connect(spinMonth_2, SIGNAL(valueChanged(int)), this, SLOT(on_spinMonth_2_valueChanged(int)));
    connect(spinYear_2, SIGNAL(valueChanged(int)), this, SLOT(on_spinYear_2_valueChanged(int)));

    time_t seconds = time(NULL);
    struct tm* timenow = localtime(&seconds);
    today = Date(timenow->tm_mday, timenow->tm_mon+1, timenow->tm_year+1900);
    ui->todayLabel->setText(today.getStrDate());
    ui->newdayLabel->setText(newday.getStrDate());

    date_list = nullptr;
    list_sz = 0;
    current_file = FileWork("/home/dimas/Документы/LR2_/LR2_Task1/dates.txt");
    ui->fileNameLabel->setText("Current: " + *(current_file.getFile()));

    if (current_file.readFile(date_list, list_sz) == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Не удалось прочитать из-за неправильного формата дат. Используйте ДД.ММ.ГГГГ");
    }
    createTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fileSelectButton_clicked() //ошибки на вводе
{
    current_file = QFileDialog::getOpenFileName(this, tr("Open Txt File"), "/home/", tr("Text File (*.txt)"));
    ui->fileNameLabel->setText("Current: " + *(current_file.getFile()));

    if (current_file.readFile(date_list, list_sz) == 0)
    {
        QMessageBox::warning(this, "Внимание!", "Не удалось прочитать файл из-за неправильного формата дат. Используйте ДД.ММ.ГГГГ");
    }
    createTable();
}
void MainWindow::createTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    //ui->tableWidget->setHorizontalHeaderLabels(QStringList() << trUtf8("День") << trUtf8("Месяц") << trUtf8("Год") << trUtf8("Разница с i+1") << trUtf8("Разница с сегодня") << trUtf8("Завтра"));
    for (int i = 0; i < list_sz; i++)
    {
        ui->tableWidget->insertRow(i);
        changeRow(i);
    }
}

void MainWindow::changeRow(int i)
{
    QString cur = QString(date_list[i].getStrDate()).mid(0, 2);
    ui->tableWidget->setItem(i,0, new QTableWidgetItem(cur));
    cur = QString(date_list[i].getStrDate()).mid(3, 2);
    ui->tableWidget->setItem(i,1, new QTableWidgetItem(cur));
    cur = QString(date_list[i].getStrDate()).mid(6, 4);
    ui->tableWidget->setItem(i,2, new QTableWidgetItem(cur));
    if (i != list_sz - 1)
        cur = QString(std::to_string(date_list[i].Duration(date_list[(i+1)])).c_str());
    else
        cur = QString("---");
    ui->tableWidget->setItem(i,3, new QTableWidgetItem(cur));
    cur = QString(std::to_string(date_list[i].Duration(today)).c_str());
    ui->tableWidget->setItem(i,4, new QTableWidgetItem(cur));
    if (date_list[i].NextDay() == date_list[i])
        cur = "01.01.10000";
    else
        cur = QString(date_list[i].NextDay().getStrDate());
    ui->tableWidget->setItem(i,5, new QTableWidgetItem(cur));
}

void MainWindow::on_prevButton_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(ui->tableWidget->item(index.row(), 0))
    {
        QString msg = date_list[index.row()].PreviousDay().getStrDate();
        if (msg == date_list[index.row()].getStrDate())
            msg = "31.12.0001BC";
        QMessageBox::information(this, "Вчера", msg);
    }
}

void MainWindow::on_isLeapButton_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(ui->tableWidget->item(index.row(), 0))
    {
        QString msg = "Год невисокосный";
        if (date_list[index.row()].isLeap())
            msg = "Год високосный";
        QMessageBox::information(this, "Год високосный?", msg);
    }
}


void MainWindow::on_weekButton_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(ui->tableWidget->item(index.row(), 0))
    {
        QString msg = 0;
        msg = QString::fromStdString("          " + std::to_string(date_list[index.row()].WeekNumInYear()) + "          ");

        QMessageBox::information(this, "Номер недели", msg);
    }
}


void MainWindow::on_bdayButton_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(ui->tableWidget->item(index.row(), 0))
    {
        QString msg = 0;
        if (date_list[index.row()].DaysTillYourBirthday(bday) == 0)
            msg = QString("С Днём Рождения!");
        else
            msg = QString::fromStdString("         " + std::to_string(date_list[index.row()].DaysTillYourBirthday(bday)) + "         ");

        qDebug() << ui->spinDay->value();
        QMessageBox::information(this, "Дней до ДР:", msg);
    }
}


void MainWindow::on_spinDay_valueChanged(int arg1) //01
{
    if (!bday.isLeap())
    {
        if (arg1 > Date::days_month[bday.getM()-1])
            ui->spinDay->setValue(Date::days_month[bday.getM()-1]);
    }
    else
    {
        if (arg1 > Date::leap_days_month[bday.getM()-1])
            ui->spinDay->setValue(Date::leap_days_month[bday.getM()-1]);
    }
    bday.setDate(arg1, bday.getM(), bday.getY());
}


void MainWindow::on_spinMonth_valueChanged(int arg1) //01
{
    if (!bday.isLeap())
    {
        if (ui->spinDay->value() > Date::days_month[arg1-1])
            ui->spinDay->setValue(Date::days_month[arg1-1]);
    }
    else
    {
        if (ui->spinDay->value() > Date::leap_days_month[arg1-1])
            ui->spinDay->setValue(Date::leap_days_month[arg1-1]);
    }
    bday.setDate(bday.getD(), arg1, bday.getY());
}


void MainWindow::on_spinYear_valueChanged(int arg1) //0001
{
    if (!Date::isLeap(arg1))
    {
        if (ui->spinDay->value() > Date::days_month[bday.getM()-1])
            ui->spinDay->setValue(Date::days_month[bday.getM()-1]);
    }
    else
    {
        if (ui->spinDay->value() > Date::leap_days_month[bday.getM()-1])
            ui->spinDay->setValue(Date::leap_days_month[bday.getM()-1]);
    }
    bday.setDate(bday.getD(), bday.getM(), arg1);
}


void MainWindow::on_editButton_clicked()
{
    /*
    if (ui->widgetAdd->isHidden())
        return;
    */

    int index = ui->tableWidget->selectionModel()->currentIndex().row();
    current_file.changeDate(newday, index, date_list, list_sz);
    changeRow(index);
}
void MainWindow::on_addButton_clicked()
{
    /*
    if (ui->widgetAdd->isHidden())
        return;
    */

    current_file.addDate(newday, date_list, list_sz);
    ui->tableWidget->insertRow(list_sz-1);
    changeRow(list_sz-1);
}

void MainWindow::on_buttonData2_clicked()
{
    qw = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(qw);
    layout->addWidget(spinDay_2);
    layout->addWidget(spinMonth_2 );
    layout->addWidget(spinYear_2);



    qw->show();
    /*
    if (ui->widgetAdd->isHidden())
        ui->widgetAdd->show();
    else
        ui->widgetAdd->hide();
    */
}


void MainWindow::on_spinDay_2_valueChanged(int arg1)
{
    if (!newday.isLeap())
    {
        if (arg1 > Date::days_month[newday.getM()-1])
            spinDay_2->setValue(Date::days_month[newday.getM()-1]);
    }
    else
    {
        if (arg1 > Date::leap_days_month[newday.getM()-1])
            spinDay_2->setValue(Date::leap_days_month[newday.getM()-1]);
    }
    newday.setDate(arg1, newday.getM(), newday.getY());
    ui->newdayLabel->setText(newday.getStrDate());
}


void MainWindow::on_spinMonth_2_valueChanged(int arg1)
{
    if (!newday.isLeap())
    {
        if (spinDay_2->value() > Date::days_month[arg1-1])
            spinDay_2->setValue(Date::days_month[arg1-1]);
    }
    else
    {
        if (spinDay_2->value() > Date::leap_days_month[arg1-1])
            spinDay_2->setValue(Date::leap_days_month[arg1-1]);
    }
    newday.setDate(newday.getD(), arg1, newday.getY());
    ui->newdayLabel->setText(newday.getStrDate());
}


void MainWindow::on_spinYear_2_valueChanged(int arg1)
{
    if (!Date::isLeap(arg1))
    {
        if (spinDay_2->value() > Date::days_month[newday.getM()-1])
            spinDay_2->setValue(Date::days_month[newday.getM()-1]);
    }
    else
    {
        if (spinDay_2->value() > Date::leap_days_month[newday.getM()-1])
            spinDay_2->setValue(Date::leap_days_month[newday.getM()-1]);
    }
    newday.setDate(newday.getD(), newday.getM(), arg1);
    ui->newdayLabel->setText(newday.getStrDate());
}

