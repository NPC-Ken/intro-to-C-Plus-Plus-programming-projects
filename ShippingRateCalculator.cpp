// Ken Stewart - Fast Freight Shipping Input Validation Program

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight, distance, rate = 0.0;

    // Prompt for weight
    cout << "Enter the weight of the package (kg): ";
    cin >> weight;

    // Validate weight
    if (weight <= 0 || weight > 20) {
        cout << "Invalid weight. It must be more than 0 and not exceed 20 kg.\n";
        cout << "Please rerun the program with a valid weight.\n";
        return 1;
    }

    // Prompt for distance
    cout << "Enter the distance the package will be shipped (miles): ";
    cin >> distance;

    // Validate distance
    if (distance < 10 || distance > 3000) {
        cout << "Invalid distance. It must be between 10 and 3000 miles.\n";
        cout << "Please rerun the program with a valid distance.\n";
        return 1;
    }

    // Determine rate based on weight
    if (weight <= 2)
        rate = 1.10;
    else if (weight <= 6)
        rate = 2.20;
    else if (weight <= 10)
        rate = 3.70;
    else // weight > 10 and <= 20
        rate = 4.80;

    // Calculate cost
    double cost = (distance / 500) * rate;

    // Display the result
    cout << fixed << setprecision(2);
    cout << "The total shipping cost is: $" << cost << endl;

    return 0;
}