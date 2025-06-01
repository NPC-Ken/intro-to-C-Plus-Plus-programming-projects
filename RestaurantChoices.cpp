// Ken Stewart - Restaurant Recommendation Program

#include <iostream>
#include <string>
using namespace std;

int main() {
    string vegetarianInput, veganInput, glutenFreeInput;
    bool vegetarian = false, vegan = false, glutenFree = false;

    // Ask for dietary restrictions
    cout << "Are you vegetarian? ";
    cin >> vegetarianInput;

    cout << "Are you vegan? ";
    cin >> veganInput;

    cout << "Are you gluten-free? ";
    cin >> glutenFreeInput;

    // Convert user input to lowercase logic (basic yes/no check)
    if (vegetarianInput == "yes" || vegetarianInput == "Yes") {
        vegetarian = true;
    }
    if (veganInput == "yes" || veganInput == "Yes") {
        vegan = true;
    }
    if (glutenFreeInput == "yes" || glutenFreeInput == "Yes") {
        glutenFree = true;
    }

    // Show results
    cout << "\nHere are your restaurant choices:\n";

    // Joe's Gourmet Burgers
    if (!vegetarian && !vegan && !glutenFree) {
        cout << "  Joe's Gourmet Burgers\n";
    }

    // Main Street Pizza Company
    if (vegetarian && !vegan && glutenFree ||
        vegetarian && !vegan && !glutenFree ||
        vegetarian && vegan && glutenFree ||
        vegetarian && vegan && !glutenFree ||
        vegetarian && !vegan && glutenFree ||
        !vegetarian && !vegan && glutenFree) {
        cout << "  Main Street Pizza Company\n";
    }

    // Corner Cafe
    if (vegetarian && vegan && glutenFree ||
        vegetarian && vegan && !glutenFree ||
        vegetarian && !vegan && glutenFree ||
        vegetarian && !vegan && !glutenFree ||
        vegetarian) {
        cout << "  Corner Cafe\n";
    }

    // Mama's Fine Italian
    if (vegetarian && !vegan && !glutenFree) {
        cout << "  Mama's Fine Italian\n";
    }

    // The Chef's Kitchen
    if (!vegetarian && !vegan && glutenFree ||
        vegetarian && !vegan && glutenFree ||
        !vegetarian && vegan && glutenFree) {
        cout << "  The Chef's Kitchen\n";
    }

    return 0;
}