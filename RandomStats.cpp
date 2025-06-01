// Ken Stewart - Random Number File Reader

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inputFile;
    int number;
    int count = 0;
    int sum = 0;
    double average = 0.0;

    // Open the file (make sure Random.txt is in the same folder or use full path)
    inputFile.open("Random.txt");

    // Check if the file was opened successfully
    if (!inputFile) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    // Read all numbers until the end of file
    while (inputFile >> number) {
        sum += number;
        count++;
    }

    // Close the file
    inputFile.close();

    // Calculate average
    if (count > 0) {
        average = static_cast<double>(sum) / count;
    }

    // Output results
    cout << "Program by Ken Stewart" << endl;
    cout << "Total numbers: " << count << endl;
    cout << "Sum of numbers: " << sum << endl;
    cout << fixed << setprecision(3);
    cout << "Average of numbers: " << average << endl;

    return 0;
}
