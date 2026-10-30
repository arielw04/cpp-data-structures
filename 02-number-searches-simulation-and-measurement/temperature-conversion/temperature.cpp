#include "temperature.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>


const double ABSOLUTE_ZERO_C = -273.15;
const double ABSOLUTE_ZERO_F = -459.67;
const double ABSOLUTE_ZERO_K = 0.0;


// CONSTRUCTORS


Temperature::Temperature() {
    degrees = 0.0;
    scale = 'C';
    format = 'D';
}

Temperature::Temperature(double deg, char s) {
    format = 'D'; // All objects start with the default format.
 
    if (!Set(deg, s)) {
        // If Set fails due to invalid input, default to 0 Celsius.
        degrees = 0.0;
        scale = 'C';
    }
}


// PUBLIC MEMBER FUNCTIONS

void Temperature::Input() {
    double temp_deg;
    char temp_scale;
    bool is_valid_input = false;

    do {
        std::cout << "Enter temperature (e.g., 25 C): ";
        std::cin >> temp_deg >> temp_scale;

        if (IsValid(temp_deg, temp_scale)) {
            degrees = temp_deg;
            scale = toupper(temp_scale);
            is_valid_input = true;
        }
        else {
            std::cout << "Invalid temperature. Try again: " << std::endl;
        }
    } while (!is_valid_input);
}

void Temperature::Show() const {
    switch (format) {
    case 'L': // Long format: 298.15 K
        std::cout << degrees << " ";
        if (scale == 'C') std::cout << "Celsius";
        else if (scale == 'F') std::cout << "Fahrenheit";
        else if (scale == 'K') std::cout << "Kelvin";
        break;

    case 'P': // Precision-1 format: 77.0 F
    {
       
        std::ios_base::fmtflags original_flags = std::cout.flags();
        std::streamsize original_precision = std::cout.precision();

    
        std::cout << std::fixed << std::setprecision(1) << degrees << " " << scale;
        std::cout.flags(original_flags);
        std::cout.precision(original_precision);
    }
    break;

    case 'D': // Default format: -10.5 C
    default:
        std::cout << degrees << " " << scale;
        break;
    }
}

bool Temperature::Set(double deg, char s) {
    if (IsValid(deg, s)) {
        degrees = deg;
        scale = toupper(s);
        return true;
    }
    return false; // Return false if temperature is invalid; object is unchanged.
}

double Temperature::GetDegrees() const {
    return degrees;
}

char Temperature::GetScale() const {
    return scale;
}

bool Temperature::SetFormat(char f) {
    if (f == 'D' || f == 'P' || f == 'L') {
        format = f;
        return true;
    }
    return false; // Return false for an invalid format code.
}

bool Temperature::Convert(char sc) {
    char target_scale = toupper(sc);

    // 1. Validate the target scale.
    if (target_scale != 'C' && target_scale != 'F' && target_scale != 'K') {
        return false;
    }

    // 2. If no conversion is needed, return true.
    if (target_scale == scale) {
        return true;
    }

    // 3. Convert current temperature to a Celsius first.
    double degrees_in_celsius;
    if (scale == 'F') {
        degrees_in_celsius = (degrees - 32.0) * 5.0 / 9.0;
    }
    else if (scale == 'K') {
        degrees_in_celsius = degrees - 273.15;
    }
    else { 
        degrees_in_celsius = degrees;
    }

    // 4. Convert from Celsius to the target scale.
    double new_degrees;
    if (target_scale == 'F') {
        new_degrees = (degrees_in_celsius * 9.0 / 5.0) + 32.0;
    }
    else if (target_scale == 'K') {
        new_degrees = degrees_in_celsius + 273.15;
    }
    else { // Target is Celsius
        new_degrees = degrees_in_celsius;
    }

    // 5. Update the object's state.
    degrees = new_degrees;
    scale = target_scale;
    return true;
}

int Temperature::Compare(const Temperature& d) const {
    // Convert both temperatures to Kelvin 
    double this_in_kelvin = this->ConvertToKelvin();
    double d_in_kelvin = d.ConvertToKelvin();

    
    const double EPSILON = 0.0001;

    if (this_in_kelvin < d_in_kelvin - EPSILON) {
        return -1; // Calling object is colder.
    }
    else if (this_in_kelvin > d_in_kelvin + EPSILON) {
        return 1;  // Calling object is hotter.
    }
    else {
        return 0;  // Temperatures are essentially equal.
    }
}

// EXTRA CREDIT

void Temperature::Increment(int deg, char sc) {
    char inc_scale = toupper(sc);
    
    if (inc_scale != 'C' && inc_scale != 'F' && inc_scale != 'K') {
        return;
    }

    // A change in Celsius is equivalent to a change in Kelvin.
 
    double delta_celsius = (inc_scale == 'F') ? (deg * 5.0 / 9.0) : static_cast<double>(deg);

   
    double final_delta = (this->scale == 'F') ? (delta_celsius * 9.0 / 5.0) : delta_celsius;

    
    double new_degrees = this->degrees + final_delta;
    if (IsValid(new_degrees, this->scale)) {
        this->degrees = new_degrees;
    }
    
}


// PRIVATE HELPER FUNCTIONS


bool Temperature::IsValid(double deg, char s) const {
    char upper_s = toupper(s);
    switch (upper_s) {
    case 'C': return deg >= ABSOLUTE_ZERO_C;
    case 'F': return deg >= ABSOLUTE_ZERO_F;
    case 'K': return deg >= ABSOLUTE_ZERO_K;
    default:  return false; 
    }
}

double Temperature::ConvertToKelvin() const {
    switch (scale) {
    case 'C':
        return degrees + 273.15;
    case 'F':
        // Convert F to C, then C to K.
        return ((degrees - 32.0) * 5.0 / 9.0) + 273.15;
    case 'K':
        return degrees;
    default:
        return 0.0; 
    }
}