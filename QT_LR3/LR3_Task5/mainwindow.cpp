#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QFont f("Times", 18);                   //creating a local variable font
    //ui->numFileLabel->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    current_path = QFileDialog::getExistingDirectory(this, tr("Открыть папку/файл"), "/home/dimas/Документы/LR3"); //tr("Text File (*.txt)")
    ui->currentLabel->setText("Текущий путь: " + current_path);
    std::pair <long long, long long> numDirFile = FileCalc::calcDirFile(current_path.toStdString());
    ui->numFileLabel->setText("Общее количество подпапок: " + QString::number(numDirFile.first));
    ui->numDirLabel->setText("Общее количество файлов: " + QString::number(numDirFile.second));
}

