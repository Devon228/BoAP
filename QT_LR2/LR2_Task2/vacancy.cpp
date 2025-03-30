#include "vacancy.h"

Vacancy::Vacancy(std::string name1, std::string job1, int wage1, int vacation1, bool req_he1, int min_age1, int max_age1, int exp1)
{
    name = name1;
    job = job1;
    wage =  wage1;
    vacation = vacation1;
    req_he = req_he1;
    min_age = min_age1;
    max_age = max_age1;
    exp = exp1;
}
Vacancy::~Vacancy()
{

}

std::string Vacancy::getName()
{
    return name;
}
std::string Vacancy::getJob()
{
    return job;
}
int Vacancy::getWage()
{
    return wage;
}
int Vacancy::getVac()
{
    return vacation;
}
bool Vacancy::getReqHE()
{
    return req_he;
}
int Vacancy::getMinAge()
{
    return min_age;
}
int Vacancy::getMaxAge()
{
    return max_age;
}
int Vacancy::getExp()
{
    return exp;
}
