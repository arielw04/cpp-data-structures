#include "sphere.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>   // REQUIRED for toupper()

const double PI = 3.14159;

// Seed random generator ONCE
static bool seeded = false;

// ---------- Helper Functions ----------

bool Sphere::isValidColor(char c) const
{
    c = toupper(c);
    return (c == 'B' || c == 'R' || c == 'P' ||
        c == 'Y' || c == 'G' || c == 'L' ||
        c == 'M');
}

char Sphere::randomColor() const
{
    const char colors[] = { 'B','R','P','Y','G','L','M' };
    return colors[rand() % 7];
}

const char* Sphere::colorToWord() const
{
    switch (toupper(color))
    {
    case 'B': return "Blue";
    case 'R': return "Red";
    case 'P': return "Purple";
    case 'Y': return "Yellow";
    case 'G': return "Green";
    case 'L': return "Black";
    case 'M': return "Maroon";
    default:  return "Unknown";
    }
}

// ---------- Constructors ----------

Sphere::Sphere()
{
    if (!seeded)
    {
        srand((unsigned)time(0));
        seeded = true;
    }

    radius = 1.0;
    color = randomColor();
}

Sphere::Sphere(double r, char c)
{
    if (!seeded)
    {
        srand((unsigned)time(0));
        seeded = true;
    }

    radius = (r > 0.0) ? r : 1.0;

    if (isValidColor(c))
        color = toupper(c);
    else
        color = randomColor();
}

// ---------- Accessors ----------

double Sphere::getRadius() const
{
    return radius;
}

char Sphere::getColor() const
{
    return color;
}

double Sphere::getDiameter() const
{
    return 2 * radius;
}

double Sphere::getSurfaceArea() const
{
    return 4 * PI * radius * radius;
}

double Sphere::getVolume() const
{
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

// ---------- Mutators ----------

void Sphere::setRadius(double r)
{
    if (r > 0.0)
        radius = r;
}

void Sphere::setColor(char c)
{
    if (isValidColor(c))
        color = toupper(c);
}

// ---------- Size Modifiers ----------

void Sphere::grow(double amount)
{
    if (radius + amount > 0.0)
        radius += amount;
}

void Sphere::shrink(double amount)
{
    if (radius - amount > 0.0)
        radius -= amount;
}

// ---------- Other ----------

void Sphere::randomizeColor()
{
    color = randomColor();
}

void Sphere::printSummary(int precision) const
{
    if (precision < 1 || precision > 5)
        precision = 2;

    std::cout << std::fixed << std::setprecision(precision);

    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Color: " << colorToWord() << std::endl;
    std::cout << "Diameter: " << getDiameter() << std::endl;
    std::cout << "Volume: " << getVolume() << std::endl;
    std::cout << "Surface Area: " << getSurfaceArea() << std::endl;
}
