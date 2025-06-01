#include <iostream>
using namespace std;

int main() {
    // Ken Stewart - Part 3: Nested Loops to print 10 rows of 15 '#' characters

    // Outer loop: handles 10 rows
    for (int row = 1; row <= 10; row++) {
        // Inner loop: prints 15 '#' per row
        for (int col = 1; col <= 15; col++) {
            cout << "#";
        }
        // Move to the next line after each row
        cout << endl;
    }

    return 0;
}
