#ifndef FILEPERS_H
#define FILEPERS_H

#include <QString>

class FilePers
{
    public:
        FilePers(QString new_file = "/home/dimas/Документы/LR2_/LR2_Task1/dates.txt");
        ~FilePers();

        QString* getFile();
        bool readFile(Date*& date_list, int& list_sz);\

        void add(Date date, Date*& date_list, int& list_sz);
        void change(Date date, int index,  Date*& date_list, int& list_sz);

    private:
        QString file;
};

#endif // FILEPERS_H
