#ifndef FILEVAC_H
#define FILEVAC_H

#include <QString>

class FileVac
{
    public:
        FileVac(/*QString new_file = "/home/dimas/Документы/LR2_/LR2_Task1/dates.txt"*/);
        ~FileVac();

        QString* getFile();
        /*
        bool readFile(Date*& date_list, int& list_sz);\

        void add(Date date, Date*& date_list, int& list_sz);
        void change(Date date, int index,  Date*& date_list, int& list_sz);*/

    private:
        QString file;
};

#endif // FILEVAC_H
