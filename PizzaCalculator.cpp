// Party Pizza Planner - Ken Stewart

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Named constants
const double PI = 3.14159;
const double SLICE_AREA = 14.125;   // Area of one slice in square inches
const int SLICES_PER_PERSON = 4;    // Average number of slices per person

// Function to calculate number of slices from a pizza diameter
double calculateSlices(double diameter) {
    double radius = diameter / 2.0;
    double area = PI * pow(radius, 2);
    return area / SLICE_AREA;
}

int main() {
    int numPeople;
    double pizzaDiameter;

    cout << "Welcome to the Party Pizza Planner!" << endl;
    cout << "Enter the number of people attending the party: ";
    cin >> numPeople;

    cout << "Enter the diameter of each pizza in inches: ";
    cin >> pizzaDiameter;

    double slicesPerPizza = calculateSlices(pizzaDiameter);
    int totalSlicesNeeded = numPeople * SLICES_PER_PERSON;
    double pizzasNeeded = totalSlicesNeeded / slicesPerPizza;

    cout << fixed << setprecision(1);
    cout << "\nTo feed " << numPeople << " people, you will need to order approximately "
        << pizzasNeeded << " pizzas." << endl;

    return 0;
}