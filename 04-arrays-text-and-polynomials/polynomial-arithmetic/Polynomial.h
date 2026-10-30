#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

// Global constant for the maximum degree allowed
const int MAX_DEGREE = 10;

class Polynomial
{
private:
    // Array storing coefficients for exponents 0..MAX_DEGREE
    int coeff[MAX_DEGREE + 1];

    // Stores the current degree of the polynomial
    int degree;

    // Stores the variable letter (ex: x, y, m)
    char letter;

    // Helper function that recomputes the degree after changes
    void updateDegree();

public:

    // Default constructor -> creates the zero polynomial
    Polynomial();

    // Parameterized constructor
    // Creates coefficients starting from a0 and decreasing by 1
    Polynomial(int a0);

    // Resets polynomial to zero polynomial
    void clear();

    // Evaluates polynomial at x value (default x = 0)
    int evaluate(int x = 0) const;

    // Returns coefficient of x^k
    int getCoefficient(int k) const;

    // Returns current degree of polynomial
    int getDegree() const;

    // Sets coefficient for x^k
    bool setCoefficient(int k, int value = 0);

    // Changes the variable letter used in the polynomial
    bool setLetter(char c);

    // Overloaded input operator
    friend std::istream& operator>>(std::istream& in, Polynomial& p);

    // Overloaded output operator
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);

    // Comparison operators
    friend bool operator==(const Polynomial& a, const Polynomial& b);
    friend bool operator!=(const Polynomial& a, const Polynomial& b);
    friend bool operator<(const Polynomial& a, const Polynomial& b);
    friend bool operator>(const Polynomial& a, const Polynomial& b);
    friend bool operator<=(const Polynomial& a, const Polynomial& b);
    friend bool operator>=(const Polynomial& a, const Polynomial& b);

    // Arithmetic operators
    friend Polynomial operator+(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator-(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
};

#endif
