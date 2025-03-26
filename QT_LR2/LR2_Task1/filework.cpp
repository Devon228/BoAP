#include "filework.h"

FileWork::FileWork(QString new_file)
{
    file = new_file;
}
FileWork::~FileWork()
{

}

QString* FileWork::getFile()
{
    return &file;
}

bool FileWork::readFile(Date*& date_list, int& list_sz) //ошибки на вводе
{
    std::ifstream fin(file.toStdString(), std::ios::in);

    free(date_list); //destructor

    int temp_sz = 4;
    list_sz = 0;
    std::string date_new;
    date_list = (Date*)malloc(sizeof(Date)*temp_sz);
    while (fin >> date_new)
    {
        list_sz++;
        if (list_sz > temp_sz)
        {
            temp_sz *= 2;
            date_list = (Date*)realloc(date_list, sizeof(Date)*temp_sz); //temporary size
        }

        if (date_list[list_sz-1].setDate(date_new) == false) //read error
        {
            free(date_list);
            date_list = nullptr;
            list_sz = 0;
            return false;
        }
        //qDebug() << date_new.c_str() << " " << date_list[list_sz-1].str_date;
    }

    date_list = (Date*)realloc(date_list, sizeof(Date)*list_sz); //real size
    return true;
}


void FileWork::addDate(Date date, Date*& date_list, int& list_sz) //ошибки на вводе
{
    std::ofstream fout(file.toStdString(), std::ios::in | std::ios::out | std::ios::app);
    //std::ofstream out(file, std::ios::binary | std::ios::in | std::ios::out);
    //out.seekp(pos,std::ios::beg);

    list_sz++;
    date_list = (Date*)realloc(date_list, sizeof(Date)*list_sz);
    date_list[list_sz-1].setDate(date);
    fout << date_list[list_sz-1].getStrDate() << "\n";
}

void FileWork::changeDate(Date date, int index,  Date*& date_list, int& list_sz) //ошибки на вводе
{
    std::ofstream fout(file.toStdString(), std::ios::in | std::ios::out);
    //std::ofstream out(file, std::ios::binary | std::ios::in | std::ios::out);
    int pos = index * 11;
    fout.seekp(pos, std::ios::beg);

    date_list[index].setDate(date);
    fout << date_list[index].getStrDate() << "\n";
}
