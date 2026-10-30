#include <iostream>
#include <iomanip>

int main() {
    double weight_pounds, height_feet, height_inches;
    double weight_kg, height_meters, height_total_inches;
    double bmi, min_weight_kg, max_weight_kg;
    double min_weight_pounds, max_weight_pounds;

    // Constants for conversions
    const double INCHES_TO_METERS = 0.0254;
    const double POUNDS_TO_KG = 0.4536;
    const double MIN_HEALTHY_BMI = 18.5;
    const double MAX_HEALTHY_BMI = 24.9;

    // User input
    std::cout << "Enter your height (in feet and inches):\n";
    std::cout << "Feet: ";
    std::cin >> height_feet;
    std::cout << "Inches: ";
    std::cin >> height_inches;

    // Convert height to meters
    height_total_inches = (height_feet * 12) + height_inches;
    height_meters = height_total_inches * INCHES_TO_METERS;
    std::cout << "(Your height in meters is " << std::fixed << std::setprecision(2) << height_meters << " m)\n";

    std::cout << "Enter your weight (in pounds): ";
    std::cin >> weight_pounds;

    // Convert weight to kilograms
    weight_kg = weight_pounds * POUNDS_TO_KG;
    std::cout << "(Your weight in kilograms is " << std::fixed << std::setprecision(2) << weight_kg << " kg)\n";

    // Calculate BMI
    bmi = weight_kg / (height_meters * height_meters);

    // Calculate minimum and maximum weight for healthy BMI range
    min_weight_kg = MIN_HEALTHY_BMI * (height_meters * height_meters);
    max_weight_kg = MAX_HEALTHY_BMI * (height_meters * height_meters);

    // Convert back to pounds
    min_weight_pounds = min_weight_kg / POUNDS_TO_KG;
    max_weight_pounds = max_weight_kg / POUNDS_TO_KG;

    // Output results
    std::cout << "Your BMI is " << std::fixed << std::setprecision(2) << bmi << "\n";
    std::cout << "Your minimum healthy weight is " << std::fixed << std::setprecision(2) << min_weight_pounds << " lbs\n";
    std::cout << "Your maximum healthy weight is " << std::fixed << std::setprecision(2) << max_weight_pounds << " lbs\n";

    return 0;
}