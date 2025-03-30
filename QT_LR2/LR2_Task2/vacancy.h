#ifndef VACANCY_H
#define VACANCY_H

#include <string>

class Vacancy
{
    public:
        Vacancy(std::string name1, std::string job1, int wage1, int vacation1, bool req_he1, int min_age1, int max_age1, int exp1);\
        ~Vacancy();

    public:
        std::string getName();
        std::string getJob();
        int getWage();
        int getVac();
        bool getReqHE();
        int getMinAge();
        int getMaxAge();
        int getExp();
        Vacancy& operator=(const Vacancy& other)
        {
            if (this == &other)
                return *this;

            this->name = other.name;
            this->job = other.job;
            this->wage =  other.wage;
            this->vacation = other.vacation;
            this->req_he = other.req_he;
            this->min_age = other.min_age;
            this->max_age = other.max_age;
            this->exp = other.exp;

            return *this;
        }

    private:
        std::string name; //30
        std::string job; //30
        int wage;
        int vacation;
        bool req_he;
        int min_age;
        int max_age;
        int exp;
};



#endif // VACANCY_H
