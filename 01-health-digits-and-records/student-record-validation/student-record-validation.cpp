#include <iostream>
using namespace std;


// Global Boundary Constants

const double MIN_GPA = 0.0;
const double MAX_GPA = 4.0;

const int MIN_CREDITS = 0;
const int MAX_CREDITS = 180;


// Student structure
struct Student
{
    int id;
    double gpa;
    int credits;
};


// Constructs and returns a Student with clamped values
Student makeStudent(int id, double gpa, int credits)
{
    Student s;
    s.id = id;

    if (gpa < MIN_GPA)
        s.gpa = MIN_GPA;
    else if (gpa > MAX_GPA)
        s.gpa = MAX_GPA;
    else
        s.gpa = gpa;

    if (credits < MIN_CREDITS)
        s.credits = MIN_CREDITS;
    else if (credits > MAX_CREDITS)
        s.credits = MAX_CREDITS;
    else
        s.credits = credits;

    return s;
}


// Checks if a student record is valid
bool isValidStudent(Student& s)
{
    return (s.gpa >= MIN_GPA && s.gpa <= MAX_GPA &&
        s.credits >= MIN_CREDITS && s.credits <= MAX_CREDITS);
}


// Attempts to update GPA
bool updateGPA(Student& s, double newGPA)
{
    if (newGPA >= MIN_GPA && newGPA <= MAX_GPA)
    {
        s.gpa = newGPA;
        return true;
    }
    return false;
}


// Attempts to add a specific number of credits
bool addCredits(Student& s, int creditsToAdd)
{
    if (creditsToAdd < 0)
        return false;

    if (s.credits + creditsToAdd > MAX_CREDITS)
        return false;

    s.credits += creditsToAdd;
    return true;
}


// Overloaded version: adds exactly 3 credits
bool addCredits(Student& s)
{
    if (s.credits + 3 > MAX_CREDITS)
        return false;

    s.credits += 3;
    return true;
}


// print function — DO NOT CHANGE
void printStudent(const Student& s)
{
    cout << s.id << " " << s.gpa << " " << s.credits << endl;
}


int main()
{
    Student s = makeStudent(999, 3.8, 25);
    printStudent(s);

    bool ok;
    cout << boolalpha;

    ok = updateGPA(s, MIN_GPA);
    cout << ok << endl;
    ok = updateGPA(s, MAX_GPA);
    cout << ok << endl;
    printStudent(s);

    ok = updateGPA(s, -0.1);
    cout << ok << endl;
    ok = updateGPA(s, 4.0001);
    cout << ok << endl;
    printStudent(s);

    ok = addCredits(s, 0);
    cout << ok << endl;
    ok = addCredits(s, -5);
    cout << ok << endl;
    printStudent(s);

    ok = addCredits(s);
    cout << ok << endl;
    printStudent(s);

    s.credits = MAX_CREDITS - 3;
    printStudent(s);

    ok = addCredits(s, 1);
    cout << ok << endl;
    printStudent(s);

    Student s2 = makeStudent(100, 5.0, 10);
    Student s3 = makeStudent(101, 3.0, -1);

    printStudent(s2);
    ok = isValidStudent(s2);
    cout << ok << endl;

    printStudent(s3);
    ok = isValidStudent(s3);
    cout << ok << endl;

    return 0;
}
