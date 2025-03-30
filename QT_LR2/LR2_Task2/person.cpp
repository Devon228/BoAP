#include "person.h"

Person::Person(std::string name1, QDate bdate1, std::string want_job1, bool is_he1, int want_wage1, int exp1)
{
    name = name1;
    bdate = bdate1;
    want_job = want_job1;
    is_he = is_he1;
    want_wage = want_wage1;
    exp = exp1;
}
Person::~Person()
{

}
std::string Person::getName()
{
    return name;
}
QDate Person::getBDate()
{
    return bdate;
}
int Person::getAge()
{
    //return bdate.daysTo(QDate::currentDate());
    int age = QDate::currentDate().year() - bdate.year();//наш максимальный возраст на текущий момент
    if(QDate(0,bdate.month(),bdate.day()) > QDate(0, QDate::currentDate().month(), QDate::currentDate().day()))
        --age;

    return age;
}
bool Person::getHE()
{
    return is_he;
}
std::string Person::getJob()
{
    return want_job;
}
int Person::getWage()
{
    return want_wage;
}
int Person::getExp()
{
    return exp;
}
