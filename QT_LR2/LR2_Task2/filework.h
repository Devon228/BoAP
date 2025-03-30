#ifndef FILEWORK_H
#define FILEWORK_H

#include <fstream>
#include <QString>
#include <vector>
#include "vacancy.h"
#include "person.h"

class FileWork
{
public:
    FileWork(QString v_file = "/home/dimas/Документы/LR2_/LR2_Task2/vac.txt", QString p_file = "/home/dimas/Документы/LR2_/LR2_Task2/pers.txt");
    ~FileWork();

    QString* getFileV();

    void setVFile(QString new_v_file);

    bool readVFile(std::vector <Vacancy> &v, int& v_sz);
    void saveVFile(std::vector <Vacancy> &v, int& v_sz);

    QString* getFileP();

    void setPFile(QString new_p_file);

    bool readPFile(std::vector <Person> &p, int& p_sz);
    void savePFile(std::vector <Person> &p, int& p_sz);

    void clearVFile();
    void clearPFile();

private:
    QString file_vac, file_pers;
};

#endif // FILEWORK_H
