#ifndef DATE_H
#define DATE_H

// Date class represents a valid calendar date
class Date
{
public:

    // Default constructor sets date to 1/1/2025
    Date();

    // Parameter constructor initializes date if valid,
    // otherwise resets to default
    Date(int m, int d, int y);

    // Conversion constructor parses "month/day/year"
    // If invalid, resets to default
    Date(const char* mdy);

    // Prompts user to enter a valid date
    void Input();

    // Accessor functions
    int GetMonth() const;
    int GetDay() const;
    int GetYear() const;

    // Sets date if valid and returns true, otherwise false
    bool Set(int m, int d, int y);

    // Moves date forward by one day
    void Increment();

    // Moves date backward by one day
    void Decrement();

    // Returns day of week (0 = Sunday ... 6 = Saturday)
    int DayofWeek() const;

    // Compares two dates (-1, 0, 1)
    int Compare(const Date& d) const;

    // Prints detailed format: DayName M/D/Y
    void ShowByDay() const;

    // Prints full calendar for the month
    void ShowByMonth() const;

private:

    // Private data members
    int month;
    int day;
    int year;

    // Default date constants
    static const int DEFAULT_MONTH = 1;
    static const int DEFAULT_DAY = 1;
    static const int DEFAULT_YEAR = 2025;

    // Helper functions used internally

    void SetToDefault();
    bool IsValid(int m, int d, int y) const;
    bool IsLeap(int y) const;
    int DaysInMonth(int m, int y) const;

    const char* MonthName(int m) const;
    const char* DayName(int dow) const;

    bool ParseMDY(const char* mdy, int& m, int& d, int& y) const;
};

#endif