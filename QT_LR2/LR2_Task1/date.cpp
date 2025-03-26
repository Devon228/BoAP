#include "date.h"

Date::Date(int nd, int nm, int ny) : d(nd), m(nm), y(ny)
{
    this->formatDate();
}
Date::Date(std::string date)
{
    d = stoi(date.substr(0, 2));
    m = stoi(date.substr(3, 2));
    y = stoi(date.substr(6, 4));
    this->formatDate();
}
Date::~Date()
{

}

bool Date::setDate (int nd, int nm, int ny)
{
    if (1 <= ny && ny <= 9999 && 1 <= nm && nm <= 12 && 1 <= nd)
    {
        if ((!isLeap(ny) && nd <= days_month[nm-1]) || (isLeap(ny) && nd <= leap_days_month[nm-1]))
        {
            d = nd;
            m = nm;
            y = ny;
            this->formatDate();

            return 1;
        }
    }

    return 0;
}
bool Date::setDate (std::string date)
{
    if (date.size() == 10 && date[2] == '.' && date[5] == '.' && isDig(date[0]) && isDig(date[1]) && isDig(date[3]) && isDig(date[4]) && isDig(date[6]) && isDig(date[7]) && isDig(date[8]) && isDig(date[9]))
    {
        int nd = stoi(date.substr(0, 2));
        int nm = stoi(date.substr(3, 2));
        int ny = stoi(date.substr(6, 4));
        return setDate(nd, nm, ny);
    }
    return 0;
}
bool Date::setDate (Date date)
{
    d = date.d;
    m = date.m;
    y = date.y;
    this->formatDate();

    return 1;
}
bool Date::isDig (char c)
{
    return ('0' <= c && c <= '9');
}

Date Date::NextDay()
{
    Date next;
    if (d == 31 && m == 12 && y == 9999)
    {
        next.setDate(31, 12, 9999);
        return next;
    }
    if (!isLeap())
    {
        //qDebug() << d << " " << m << " " <<  days_month[m-1];
        if (d != days_month[m-1])
            next.setDate(this->d + 1, this->m, this->y);
        else
            if (m < 11)
                next.setDate(1, this->m + 1, this->y);
            else
                next.setDate(1, 1, this->y + 1);
    }
    else
    {
        if (d != leap_days_month[m-1])
            next.setDate(this->d + 1, this->m, this->y);
        else
            if (m < 11)
                next.setDate(1, this->m + 1, this->y);
            else
                next.setDate(1, 1, this->y + 1);
    }

    return next;
}
Date Date::PreviousDay()
{
    Date prev;

    if (d == 1 && m == 1 && y == 1)
    {
        prev.setDate(1, 1, 1);
        return prev;
    }
    if (!isLeap())
    {
        if (d != 1)
            prev.setDate(this->d - 1, this->m, this->y);
        else
            if (m > 1)
                prev.setDate(days_month[this->m - 1], this->m - 1, this->y);
            else
                prev.setDate(31, 12, this->y - 1);
    }
    else
    {
        if (d != 1)
            prev.setDate(this->d - 1, this->m, this->y);
        else
            if (m > 1)
                prev.setDate(leap_days_month[this->m - 1], this->m - 1, this->y);
            else
                prev.setDate(31, 12, this->y - 1);
    }

    return prev;
}
bool Date::isLeap()
{
    if (y % 400 == 0)
        return true;
    else if (y % 100 == 0)
        return false;
    else if (y% 4 == 0)
        return true;
    else
        return false;
}
bool Date::isLeap(int ny)
{
    if (ny % 400 == 0)
        return true;
    else if (ny % 100 == 0)
        return false;
    else if (ny% 4 == 0)
        return true;
    else
        return false;
}

int Date::dayNumFrom0() //mb DaysFrom0toYear dney v godax s 0001 po YYYY
{
    int day_num_0 = dayNumInYear();
    day_num_0 += (y - 1) * 365 + ((y-1) / 4 - (y-1) / 100 + (y-1)/400);

    return day_num_0;
}
short Date::dayNumInYear()
{
    short day_num = 0;

    if (!isLeap())
        for (int i = 0; i < m - 1; i++)
            day_num += days_month[i];
    else
        for (int i = 0; i < m - 1; i++)
            day_num += leap_days_month[i];

    day_num += d;

    return day_num;
}
short Date::WeekNumInYear()
{
    return (dayNumInYear() - 1) / 7 + 1;
}

int Date::DaysTillYourBirthday(Date bdaydate)
{
    return bdaydate.dayNumFrom0() - this->dayNumFrom0();
}
int Date::Duration(Date date)
{
    return abs(date.dayNumFrom0() - this->dayNumFrom0());
}

void Date::formatDate ()
{
    std::string str_new = "";
    if (d <= 9)
        str_new = "0" + std::to_string(d) + ".";
    else
        str_new = std::to_string(d) + ".";

    if (m <= 9)
        str_new += "0" + std::to_string(m) + ".";
    else
        str_new += std::to_string(m) + ".";

    if (y <= 9)
        str_new += "000" + std::to_string(y);
    else if (y <= 99)
        str_new += "00" + std::to_string(y);
    else if (y <= 999)
        str_new += "0" + std::to_string(y);
    else
        str_new += std::to_string(y);

    str_date = new char[11];
    for (int i = 0; i < 10; i++)
        str_date[i] = str_new[i];
    str_date[10] = '\0';
}


int Date::getD() const
{
    return d;
}
int Date::getM() const
{
    return m;
}
int Date::getY() const
{
    return y;
}
char* Date::getStrDate() const
{
    return str_date;
}

