#include <iostream>
#include <iomanip>
#include <cmath>  // for ceil
using namespace std;

// Constants
const float SQFT_PER_GALLON = 95.0;
const float HOURS_PER_95SQFT = 7.0;
const float LABOR_RATE = 31.00;

// Function prototypes
int getNumberOfRooms();
float getPaintPrice();
float getTotalSquareFeet(int rooms);
int calculateGallonsRequired(float totalSqFt);
float calculateLaborHours(float totalSqFt);
void displayResults(int gallons, float paintPrice, float totalSqFt, float laborHours);

int main()
{
    cout << "Kenneth Stewart\n" << endl;

    int rooms = getNumberOfRooms();
    float paintPrice = getPaintPrice();
    float totalSqFt = getTotalSquareFeet(rooms);
    int gallons = calculateGallonsRequired(totalSqFt);
    float laborHours = calculateLaborHours(totalSqFt);

    displayResults(gallons, paintPrice, totalSqFt, laborHours);

    return 0;
}

int getNumberOfRooms()
{
    int rooms;
    do {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
        if (rooms < 1)
            cout << "ERROR: Enter 1 or greater." << endl;
    } while (rooms < 1);
    return rooms;
}

float getPaintPrice()
{
    float price;
    do {
        cout << "Enter the price of the paint, per gallon: $";
        cin >> price;
        if (price < 8.0)
            cout << "ERROR: Price must be at least $8.00 per gallon." << endl;
    } while (price < 8.0);
    return price;
}

float getTotalSquareFeet(int rooms)
{
    float total = 0.0, sqft;

    for (int i = 1; i <= rooms; ++i) {
        do {
            cout << "Room " << i << ": Enter the area of wall space in square feet: ";
            cin >> sqft;
            if (sqft < 0)
                cout << "ERROR: Wall space cannot be negative." << endl;
        } while (sqft < 0);
        total += sqft;
    }

    return total;
}

int calculateGallonsRequired(float totalSqFt)
{
    return static_cast<int>(ceil(totalSqFt / SQFT_PER_GALLON));
}

float calculateLaborHours(float totalSqFt)
{
    return (totalSqFt / SQFT_PER_GALLON) * HOURS_PER_95SQFT;
}

void displayResults(int gallons, float paintPrice, float totalSqFt, float laborHours)
{
    float paintCost = gallons * paintPrice;
    float laborCost = laborHours * LABOR_RATE;
    float totalCost = paintCost + laborCost;

    cout << "\nESTIMATED CHARGES\n" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Gallons of paint:      " << gallons << endl;
    cout << "Price per gallon:     $" << paintPrice << endl;
    cout << "Paint cost:           $" << paintCost << endl;
    cout << "Hours of labor:        " << laborHours << endl;
    cout << "Cost of labor:        $" << laborCost << endl;
    cout << "Total charges:        $" << totalCost << endl;
}

