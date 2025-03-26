#ifndef DATE_H
#define DATE_H

#include <string>
#include <cmath>
#include <QDebug>

class Date
{
    public:
        Date(int nd = 1, int nm = 1, int ny = 1);
        Date(std::string date);
        ~Date();

        bool setDate (int nd, int nm, int ny);
        bool setDate (std::string date);
        bool setDate (Date date);
        static bool isDig(char c);

        Date NextDay();
        Date PreviousDay();
        bool isLeap();
        static bool isLeap(int ny);

        short WeekNumInYear();

        int DaysTillYourBirthday(Date bdaydate);
        int Duration(Date date);

        int getD() const;
        int getM() const;
        int getY() const;
        char* getStrDate() const;

        static constexpr int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        static constexpr int leap_days_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    private:
        int dayNumFrom0(); //mb DaysFrom0toYear dney v godax s 0001 po YYYY
        short dayNumInYear();
        void formatDate();
        int d, m, y;
        char* str_date; //10

};

inline bool operator==(const Date& lhs, const Date& rhs)
{
    return (lhs.getD() == rhs.getD() && lhs.getM() == rhs.getM() && lhs.getY() == rhs.getY());
}


#endif // DATE_H
