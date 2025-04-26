#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
    //ui->pushButton->setFocusPolicy(Qt::NoFocus);
    //ui->pushButton_2->setFocusPolicy(Qt::NoFocus);

    /*for (int i = 0;i<alphabet.size();++i)
    {
        buttons[i]->setText(QString(alphabet[i]));
    }*/

    cur_file = "/home/dimas/Документы/LR5/Task_1/aboba.txt";
    ui->label_7->setText("Текущий: " + cur_file);


    wrongPressed = 0;
    rightPressed = 0;
    prevWrongPressed = 0;
    rightWords = 0;
    writtenText = "";

    cursor = QTextCursor(ui->textEdit->textCursor());
    QTextCharFormat format;
    format.setForeground(QBrush(QColor("red")));
    cursor.setCharFormat(format);

    timer.setInterval(TIMER_INTERVAL);

    connect(&timer, &QTimer::timeout, this, [this] ()
            {
                currentTime += TIMER_INTERVAL / 1000;

                ui->textEdit_2->setPlainText(textToWrite);
                //ui->textEdit->setPlainText(writtenText);

                ui->label_2->setText(QString::number(currentTime));
                ui->label_4->setText(QString::number(rightWords / (currentTime / 60.0)));
                if (rightPressed + wrongPressed != 0)
                    ui->label_6->setText(QString::number(rightPressed / (rightPressed + wrongPressed) * 100) + "%");
                else
                    ui->label_6->setText("100%");

                if (textToWrite == "")
                {
                    QMessageBox msgBox;
                    qDebug() << rightWords << " " << wrongWords << " " << rightPressed << " " << wrongPressed << "\n";
                    msgBox.setText("Ваши результаты:\n" + QString::number(rightWords / (rightWords + wrongWords) * 100) + "% корректных слов текста из " + QString::number(writtenText.size()) + " символов за " + QString::number(currentTime) + " сек со средней точностью " + QString::number(rightPressed / (rightPressed + wrongPressed) * 100) + "%");

                    msgBox.exec();

                    this->close();
                }
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{

    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Space){
            keyPressEvent(keyEvent);
            return true;
        }
        else{
            return QMainWindow::eventFilter(watched,event);
        }
    }
    else
        return QMainWindow::eventFilter(watched,event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->text().toLower();
    for (int i = 0; i < alphabet.size(); i++)
    {
        if (alphabet[i].unicode() == event->text().toLower())
        {
            //buttons[i]->setPalette(QPalette(Qt::yellow));

            if (alphabet[i] == " ")
            {
                if (writtenText.size() && writtenText.back() != " ")
                {
                    if (prevWrongPressed == wrongPressed)
                    {
                        rightWords++;
                    }
                    else
                    {
                        wrongWords++;
                        prevWrongPressed = wrongPressed;
                    }
                }
            }

            if (event->text() != textToWrite.front())
            {
                //ui->textEdit->setTextColor(QColor("red"));
                format.setForeground(QBrush(QColor("red")));
                wrongPressed++;
            }
            else
            {
                //ui->textEdit->setTextColor(QColor("green"));
                format.setForeground(QBrush(QColor("green")));
                rightPressed++;
            }
            //ui->textEdit->append(event->text());

            cursor.setCharFormat(format);
            cursor.insertText(event->text());

            writtenText.append(event->text());
            textToWrite.remove(0, 1);

            break;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    cur_file = QFileDialog::getOpenFileName(this, tr("Open Txt File"), "/home/dimas/Документы/LR5/Task_1", tr("Text File (*.txt)"));
    ui->label_7->setText("Текущий: " + cur_file);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->comboBox->currentIndex() == 0)
    {
        alphabet = "ßqwertzuiopüasdfghjklöäyxcvbnmßqwertzuiopüasdfghjklöäyxcvbnm ";
    }
    else if (ui->comboBox->currentIndex() == 1)
    {
        alphabet = "éèçàazertyuiopqsdfghjklmùwxcvbnèçàazertyuiopqsdfghjklmùwxcvbn ";
    }
    else if (ui->comboBox->currentIndex() == 2)
    {
        alphabet = "ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوز ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوز";
    }
    else if (ui->comboBox->currentIndex() == 3)
    {
        alphabet = "qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm ";
    }
    else if (ui->comboBox->currentIndex() == 4)
    {
        alphabet = "ёйцукенгшўзхфывапролджэячсмітьбюйцукенгшўзхфывапролджэячсмітьбю ";
    }
    else if (ui->comboBox->currentIndex() == 5)
    {
        alphabet = "קראטוןםפשדגכעיחלךףזסבהנמצתץקראטוןםפשדגכעיחלךףזסבהנמצתץ ";
    }
    else
    {
        std::ifstream fin(cur_file.toStdString(), std::ios::in);
        std::string s1;
        while (getline(fin, s1))
        {
            textToWrite.append(QString::fromStdString(s1));
        }
        alphabet = "ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوز ضصثقفغعهخحجدشسيبلاتنمكطئءؤرلاىةوزקראטוןםפשדגכעיחלךףזסבהנמצתץקראטוןםפשדגכעיחלךףזסבהנמצתץёйцукенгшўзхфывапролджэячсмітьбюйцукенгшўзхфывапролджэячсмітьбюéèçàazertyuiopqsdfghjklmùwxcvbnèçàazertyuiopqsdfghjklmùwxcvbnßqwertzuiopüasdfghjklöäyxcvbnmßqwertzuiopüasdfghjklöäyxcvbnmqwertyuiopasdfghjkl;'zxcvbnmqwertyuiopasdfghjklzxcvbnm ";
    }

    if (textToWrite.size() == 0) //not 6
    {
        QRandomGenerator rng;

        for (int i = 0; i < TEXT_SZ; i++)
        {
            textToWrite.append(alphabet[rng() % alphabet.size()]);
            if (rng() % PROBABILITY_OF_SPACE == 0)
                textToWrite.append(" ");
        }
    }

    textToWrite.append(" ");

    ui->pushButton_2->setDisabled(1);
    ui->pushButton->setDisabled(1);
    ui->comboBox->setDisabled(1);
    timer.start();
}

