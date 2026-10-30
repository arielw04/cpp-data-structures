#include "date.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Default constructor sets date to 1/1/2025
Date::Date()
{
    SetToDefault();
}

// Parameter constructor initializes if valid, otherwise default
Date::Date(int m, int d, int y)
{
    if (IsValid(m, d, y))
    {
        month = m;
        day = d;
        year = y;
    }
    else
    {
        SetToDefault();
    }
}

// Conversion constructor parses "month/day/year"
Date::Date(const char* mdy)
{
    int m, d, y;

    if (ParseMDY(mdy, m, d, y) && IsValid(m, d, y))
    {
        month = m;
        day = d;
        year = y;
    }
    else
    {
        SetToDefault();
    }
}

// Sets default date
void Date::SetToDefault()
{
    month = DEFAULT_MONTH;
    day = DEFAULT_DAY;
    year = DEFAULT_YEAR;
}

// Checks leap year rule
bool Date::IsLeap(int y) const
{
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

// Returns number of days in month
int Date::DaysInMonth(int m, int y) const
{
    static const int days[12] =
    { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (m == 2)
        return IsLeap(y) ? 29 : 28;

    return days[m - 1];
}

// Validates full date
bool Date::IsValid(int m, int d, int y) const
{
    if (y < 1900) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > DaysInMonth(m, y)) return false;
    return true;
}

// Parses M/D/Y string
bool Date::ParseMDY(const char* mdy, int& m, int& d, int& y) const
{
    string s(mdy);

    size_t p1 = s.find('/');
    size_t p2 = s.find('/', p1 + 1);

    if (p1 == string::npos || p2 == string::npos)
        return false;

    try
    {
        m = stoi(s.substr(0, p1));
        d = stoi(s.substr(p1 + 1, p2 - p1 - 1));
        y = stoi(s.substr(p2 + 1));
    }
    catch (...)
    {
        return false;
    }

    return true;
}

// Prompts user until valid date entered
void Date::Input()
{
    int m, d, y;
    char s1, s2;

    cout << "Input date in month/day/year format: ";
    cin >> m >> s1 >> d >> s2 >> y;

    while (!(s1 == '/' && s2 == '/' && IsValid(m, d, y)))
    {
        cout << "Invalid date. Try again: ";
        cin >> m >> s1 >> d >> s2 >> y;
    }

    month = m;
    day = d;
    year = y;
}

// Accessors
int Date::GetMonth() const { return month; }
int Date::GetDay() const { return day; }
int Date::GetYear() const { return year; }

// Sets date if valid
bool Date::Set(int m, int d, int y)
{
    if (!IsValid(m, d, y))
        return false;

    month = m;
    day = d;
    year = y;
    return true;
}

// Moves date forward one day
void Date::Increment()
{
    if (day < DaysInMonth(month, year))
    {
        day++;
    }
    else
    {
        day = 1;
        if (month < 12)
            month++;
        else
        {
            month = 1;
            year++;
        }
    }
}

// Moves date backward one day
void Date::Decrement()
{
    if (month == 1 && day == 1 && year == 1900)
        return;

    if (day > 1)
    {
        day--;
    }
    else
    {
        if (month > 1)
            month--;
        else
        {
            month = 12;
            year--;
        }

        day = DaysInMonth(month, year);
    }
}

// Computes day of week using Sakamoto’s algorithm
int Date::DayofWeek() const
{
    static int t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };

    int y = year;
    y -= (month < 3);

    return (y + y / 4 - y / 100 + y / 400 + t[month - 1] + day) % 7;
}

// Compares two dates
int Date::Compare(const Date& other) const
{
    if (year != other.year)
        return (year < other.year) ? -1 : 1;

    if (month != other.month)
        return (month < other.month) ? -1 : 1;

    if (day != other.day)
        return (day < other.day) ? -1 : 1;

    return 0;
}

// Prints DayName M/D/Y
void Date::ShowByDay() const
{
    cout << DayName(DayofWeek())
        << " " << month << "/"
        << day << "/" << year;
}

// Prints calendar for the month
void Date::ShowByMonth() const
{
    cout << MonthName(month)
        << "    " << year << "\n";

    cout << "Su Mo Tu We Th Fr Sa\n";

    Date temp(month, 1, year);
    int firstDow = temp.DayofWeek();

    for (int i = 0; i < firstDow; i++)
        cout << "   ";

    int dim = DaysInMonth(month, year);

    for (int d = 1; d <= dim; d++)
    {
        cout << setw(2) << setfill('0') << d
            << setfill(' ') << " ";

        if ((firstDow + d - 1) % 7 == 6)
            cout << "\n";
    }

    if ((firstDow + dim - 1) % 7 != 6)
        cout << "\n";
}
// Returns full month name
const char* Date::MonthName(int m) const
{
    static const char* names[12] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };

    if (m < 1 || m > 12)
        return "";

    return names[m - 1];
}

// Returns full day name
const char* Date::DayName(int dow) const
{
    static const char* names[7] = {
        "Sunday","Monday","Tuesday","Wednesday",
        "Thursday","Friday","Saturday"
    };

    if (dow < 0 || dow > 6)
        return "";

    return names[dow];
}