#include "filework.h"

FileWork::FileWork(QString v_file, QString p_file)
{
    file_vac = v_file;
    file_pers = p_file;
}
FileWork::~FileWork()
{

}

QString* FileWork::getFileV()
{
    return &file_vac;
}

void FileWork::setVFile(QString new_v_file)
{
    this->file_vac = new_v_file;
}

bool FileWork::readVFile(std::vector <Vacancy> &v, int& v_sz)
{
    std::ifstream fin(file_vac.toStdString(), std::ios::in);

    v.clear();
    v_sz = 0;

    std::string n1, j1;
    int v1, w1, req_he1, min_age1, max_age1, exp1;
    while (fin >> n1)
    {
        fin >> j1 >> w1 >> v1 >> req_he1 >> min_age1 >> max_age1 >> exp1;

        if (fin.fail())
            return 0;

        v.push_back(Vacancy(n1, j1, w1, v1, req_he1, min_age1, max_age1, exp1));
        v_sz++;
    }

    return true;
}

void FileWork::saveVFile(std::vector <Vacancy> &v, int& v_sz)
{
    std::ofstream fout(file_vac.toStdString(), std::ios::out);

    for (int i = 0; i < v_sz; i++)
    {
        fout << v[i].getName() << " " << v[i].getJob() << " " << v[i].getWage() << " " << v[i].getVac() << " " << v[i].getReqHE() << " " << v[i].getMinAge() << " " << v[i].getMaxAge() << " " << v[i].getExp() << "\n";
    }
}



QString* FileWork::getFileP()
{
    return &file_pers;
}

void FileWork::setPFile(QString new_p_file)
{
    this->file_pers = new_p_file;
}

bool FileWork::readPFile(std::vector <Person> &p, int& p_sz)
{
    std::ifstream fin(file_pers.toStdString(), std::ios::in);

    p.clear();
    p_sz = 0;

    std::string name1, want_job1;
    std::string bdate1;
    bool is_he1;
    int want_wage1,  exp1;
    while (fin >> name1)
    {
        fin >> bdate1 >>  want_job1 >> is_he1 >> want_wage1 >> exp1;

        if (fin.fail())
            return 0;

        p.push_back(Person(name1, QDate::fromString(QString::fromStdString(bdate1), "dd.MM.yyyy"), want_job1, is_he1, want_wage1, exp1));
        p_sz++;
    }

    return true;
}

void FileWork::savePFile(std::vector <Person> &p, int& p_sz)
{
    std::ofstream fout(file_pers.toStdString(), std::ios::out);

    for (int i = 0; i < p_sz; i++)
    {
        fout << p[i].getName() << " " << p[i].getBDate().toString(Qt::DefaultLocaleShortDate).toStdString() << " " << p[i].getJob() << " " << p[i].getHE() << " " << p[i].getWage() << " " << p[i].getExp() << "\n";
    }
}

void FileWork::clearPFile()
{
    std::ofstream fout(file_pers.toStdString(), std::ios::out | std::ios::trunc);
    fout.close();
}
void FileWork::clearVFile()
{
    std::ofstream fout(file_vac.toStdString(), std::ios::out | std::ios::trunc);
    fout.close();
}
