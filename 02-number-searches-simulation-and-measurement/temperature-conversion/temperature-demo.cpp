/////////////////////////////////////////////////////////
//
// main.cpp -- A tweaked and expanded test program for the Temperature class
//
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

// Helper to make the output easier to read
void print_separator() {
    cout << "\n//-----------------------------------------------\n\n";
}

int main()
{
    // ## 1. Test Constructors ##
    cout << "## 1. Testing Constructors ##" << endl;
    Temperature t1;		        // Should default to 0 Celsius
    Temperature t2(34.5, 'F');   // Should init to 34.5 Fahrenheit
    Temperature t_invalid(-5, 'k');   // Invalid (below 0 K), should default to 0 C
    Temperature t_bad_scale(99, 'R'); // Invalid scale, should default to 0 C

    cout << "t1 (default): ";
    t1.Show();
    cout << "\nt2 (34.5, 'F'): ";
    t2.Show();
    cout << "\nt_invalid (-5, 'k'): ";
    t_invalid.Show();
    cout << "\nt_bad_scale (99, 'R'): ";
    t_bad_scale.Show();
    cout << endl;

    print_separator();

    // ## 2. Test Set, Convert, and Format ##
    cout << "## 2. Testing Set, Convert, and Format on t1 ##" << endl;
    cout << "Initial t1: ";
    t1.Show();

    cout << "\nSetting t1 to 212 'F': ";
    t1.Set(212, 'F');
    t1.Show();

    cout << "\nConverting t1 to Celsius: ";
    t1.Convert('c');
    t1.Show(); // Should be 100 C

    cout << "\nChanging t1 format to Long ('L'): ";
    t1.SetFormat('L');
    t1.Show();

    cout << "\nChanging t1 format to Precision ('P'): ";
    t1.SetFormat('P');
    t1.Show();
    cout << endl;

    print_separator();

    // ## 3. Test Compare ##
    cout << "## 3. Testing Compare ##" << endl;
    Temperature t3(100, 'c');
    cout << "t1 is 100 C. t2 is 34.5 F. t3 is 100 C." << endl;

    // Compare t1 (100 C) and t3 (100 C)
    cout << "Comparing t1 and t3... Result: " << t1.Compare(t3) << " (Expected: 0)" << endl;

    // Compare t1 (100 C) and t2 (34.5 F)
    cout << "Comparing t1 and t2... Result: " << t1.Compare(t2) << " (Expected: 1, since t1 > t2)" << endl;

    // Compare t2 (34.5 F) and t1 (100 C)
    cout << "Comparing t2 and t1... Result: " << t2.Compare(t1) << " (Expected: -1, since t2 < t1)" << endl;

    print_separator();

    // ## 4. Test Increment (Extra Credit) ##
    cout << "## 4. Testing Increment on t2 (34.5 F) ##" << endl;
    cout << "Initial t2: ";
    t2.Show();

    cout << "\nIncrementing t2 by 1.5 'F': ";
    t2.Increment(1.5, 'F');
    t2.Show(); // Should be 36.0 F

    cout << "\nIncrementing t2 by 10 'C' (which is 18 'F'): ";
    t2.Increment(10, 'C');
    t2.Show(); // Should be 54.0 F
    cout << endl;

    print_separator();

    // ## 5. Test Input ##
    cout << "## 5. Testing User Input ##" << endl;
    Temperature t_user;
    // The Input() function contains its own prompt
    t_user.Input();

    cout << "\nYou entered: ";
    t_user.SetFormat('L'); // Show in long format for clarity
    t_user.Show();
    cout << endl;

    print_separator();

    cout << "All tests complete." << endl;

    return 0;
}