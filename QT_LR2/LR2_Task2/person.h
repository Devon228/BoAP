#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>
#include <QDate>

class Person
{
    public:
        Person(std::string name1, QDate bdate1, std::string want_job1,  bool is_he1, int want_wage1, int exp1);
        ~Person();
        std::string getName();
        QDate getBDate();
        int getAge();
        bool getHE();
        std::string getJob();
        int getWage();
        int getExp();


    private:
        std::string name;
        QDate bdate;
        std::string want_job;
        bool is_he;
        int want_wage;
        int exp;
};

#endif // PERSON_H
