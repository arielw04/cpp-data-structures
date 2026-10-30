#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature
{
public:
    // CONSTRUCTORS

    Temperature();

    Temperature(double deg, char s);

    // PUBLIC MEMBER FUNCTIONS

    void Input();

    void Show() const;
  
    bool Set(double deg, char s);

    double GetDegrees() const;

    char GetScale() const;

    bool SetFormat(char f);

    bool Convert(char sc);

    int Compare(const Temperature& d) const;

    // EXTRA CREDIT

    void Increment(int deg, char sc);

private:
    double degrees; // The numeric value of the temperature
    char scale;     // The scale: 'C', 'F', or 'K'
    char format;    // The display format: 'D', 'P', or 'L'

    // PRIVATE HELPER FUNCTIONS

    bool IsValid(double deg, char s) const;

    double ConvertToKelvin() const;
};

#endif
