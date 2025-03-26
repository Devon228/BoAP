#ifndef FILEWORK_H
#define FILEWORK_H

#include "date.h"
#include <fstream>
#include <QString>

class FileWork
{
    public:
        FileWork(QString new_file = "/home/dimas/Документы/LR2_/LR2_Task1/dates.txt");
        ~FileWork();

        QString* getFile();
        bool readFile(Date*& date_list, int& list_sz);\

        void addDate(Date date, Date*& date_list, int& list_sz);
        void changeDate(Date date, int index,  Date*& date_list, int& list_sz);

    private:
        QString file;
};

#endif // FILEWORK_H
