#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>

class Sphere
{
private:
    double radius;
    char color;

    bool isValidColor(char c) const;
    char randomColor() const;
    const char* colorToWord() const;

public:
    // Constructors
    Sphere();
    Sphere(double r, char c = '\0');

    // Accessors
    double getRadius() const;
    char getColor() const;
    double getDiameter() const;
    double getSurfaceArea() const;
    double getVolume() const;

    // Mutators
    void setRadius(double r);
    void setColor(char c);

    // Other functions
    void grow(double amount);
    void shrink(double amount);
    void randomizeColor();
    void printSummary(int precision = 2) const;
};

#endif
