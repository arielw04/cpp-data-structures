#include "Polynomial.h"
#include <cmath>
#include <cctype>

using namespace std;


// Recalculate the degree based on the highest non-zero coefficient
void Polynomial::updateDegree()
{
    degree = -1;

    // Scan from highest exponent downwards
    for (int i = MAX_DEGREE; i >= 0; i--)
    {
        if (coeff[i] != 0)
        {
            degree = i;
            break;
        }
    }
}


// Default constructor
// Initializes the polynomial as the zero polynomial
Polynomial::Polynomial()
{
    letter = 'x';
    clear();
}


// Parameterized constructor
// Sets a0 = parameter then decreases by 1 for each coefficient
Polynomial::Polynomial(int a0)
{
    letter = 'x';

    coeff[0] = a0;

    // Fill remaining coefficients
    for (int i = 1; i <= MAX_DEGREE; i++)
        coeff[i] = coeff[i - 1] - 1;

    updateDegree();
}


// Clears the polynomial (all coefficients = 0)
void Polynomial::clear()
{
    for (int i = 0; i <= MAX_DEGREE; i++)
        coeff[i] = 0;

    degree = -1;
}


// Evaluates polynomial using x value
int Polynomial::evaluate(int x) const
{
    int result = 0;

    // Sum ai * x^i
    for (int i = 0; i <= MAX_DEGREE; i++)
        result += coeff[i] * pow(x, i);

    return result;
}


// Returns coefficient of x^k
int Polynomial::getCoefficient(int k) const
{
    if (k >= 0 && k <= degree)
        return coeff[k];

    return 0;
}


// Returns the polynomial degree
int Polynomial::getDegree() const
{
    return degree;
}


// Sets coefficient for x^k
bool Polynomial::setCoefficient(int k, int value)
{
    // Check bounds
    if (k < 0 || k > MAX_DEGREE)
        return false;

    coeff[k] = value;

    // Update degree after change
    updateDegree();

    return true;
}


// Changes polynomial variable letter
bool Polynomial::setLetter(char c)
{
    // Ensure character is alphabetic
    if (!isalpha(c))
        return false;

    // Store as lowercase
    letter = tolower(c);

    return true;
}


// Extraction operator >>
istream& operator>>(istream& in, Polynomial& p)
{
    char var, semicolon, comma;

    // Read variable and semicolon
    in >> var >> semicolon;

    // Validate letter
    if (!isalpha(var))
    {
        p.clear();
        return in;
    }

    // Store lowercase letter
    p.letter = tolower(var);

    // Read coefficient list
    for (int i = 0; i <= MAX_DEGREE; i++)
    {
        in >> p.coeff[i];

        if (i < MAX_DEGREE)
            in >> comma;
    }

    p.updateDegree();

    return in;
}


// Insertion operator <<
ostream& operator<<(ostream& out, const Polynomial& p)
{
    // Special case: zero polynomial
    if (p.degree == -1)
    {
        out << "Polynomial of degree -1";
        return out;
    }

    bool first = true;

    // Print terms from highest degree down
    for (int i = p.degree; i >= 0; i--)
    {
        int c = p.coeff[i];

        if (c == 0)
            continue;

        // Handle sign formatting
        if (!first)
        {
            if (c > 0)
                out << " + ";
            else
            {
                out << " - ";
                c = -c;
            }
        }
        else
        {
            if (c < 0)
            {
                out << "-";
                c = -c;
            }
        }

        // Skip printing coefficient 1 for non-constant terms
        if (!(c == 1 && i != 0))
            out << c;

        // Print variable and exponent
        if (i > 0)
        {
            out << p.letter;

            if (i > 1)
                out << "^" << i;
        }

        first = false;
    }

    return out;
}


// Equality operator
bool operator==(const Polynomial& a, const Polynomial& b)
{
    if (a.letter != b.letter)
        return false;

    for (int i = 0; i <= MAX_DEGREE; i++)
        if (a.coeff[i] != b.coeff[i])
            return false;

    return true;
}


// Inequality operator
bool operator!=(const Polynomial& a, const Polynomial& b)
{
    return !(a == b);
}


// Less-than comparison (lexicographic by coefficients)
bool operator<(const Polynomial& a, const Polynomial& b)
{
    for (int i = MAX_DEGREE; i >= 0; i--)
    {
        if (a.coeff[i] != b.coeff[i])
            return a.coeff[i] < b.coeff[i];
    }

    return a.letter < b.letter;
}


// Remaining comparison operators
bool operator>(const Polynomial& a, const Polynomial& b)
{
    return b < a;
}

bool operator<=(const Polynomial& a, const Polynomial& b)
{
    return !(b < a);
}

bool operator>=(const Polynomial& a, const Polynomial& b)
{
    return !(a < b);
}


// Addition operator
Polynomial operator+(const Polynomial& a, const Polynomial& b)
{
    Polynomial result;

    result.letter = a.letter;

    // Add coefficients
    for (int i = 0; i <= MAX_DEGREE; i++)
        result.coeff[i] = a.coeff[i] + b.coeff[i];

    result.updateDegree();

    return result;
}


// Subtraction operator
Polynomial operator-(const Polynomial& a, const Polynomial& b)
{
    Polynomial result;

    result.letter = a.letter;

    // Subtract coefficients
    for (int i = 0; i <= MAX_DEGREE; i++)
        result.coeff[i] = a.coeff[i] - b.coeff[i];

    result.updateDegree();

    return result;
}


// Multiplication operator
Polynomial operator*(const Polynomial& a, const Polynomial& b)
{
    Polynomial result;

    result.letter = a.letter;

    // Initialize result coefficients
    for (int i = 0; i <= MAX_DEGREE; i++)
        result.coeff[i] = 0;

    // Multiply polynomials
    for (int i = 0; i <= MAX_DEGREE; i++)
    {
        for (int j = 0; j <= MAX_DEGREE; j++)
        {
            // Ignore terms beyond MAX_DEGREE
            if (i + j <= MAX_DEGREE)
                result.coeff[i + j] += a.coeff[i] * b.coeff[j];
        }
    }

    result.updateDegree();

    return result;
}