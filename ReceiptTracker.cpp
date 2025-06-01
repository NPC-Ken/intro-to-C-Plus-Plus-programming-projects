#include <iostream>
#include "Receipt.h"
#include "Product.h"
using namespace std;

int main() {
    // Create a Receipt with space for 3 items
    Receipt receipt1(3);

    // Add items to the receipt
    receipt1.purchase("Bread", 2.99, 2);
    receipt1.purchase("Milk", 3.49, 1);
    receipt1.purchase("Eggs", 4.99, 1);

    // Try to add a fourth item (should fail because limit is 3)
    bool added = receipt1.purchase("Butter", 2.29, 1);
    if (!added) {
        cout << "Could not add Butter — receipt is full.\n";
    }

    // Print receipt contents
    cout << "\n--- Receipt 1 ---\n";
    receipt1.print();

    // PART 2: Product Array Test
    cout << "\n--- Product Array Test ---\n";

    int size = 3;
    Product** productArray = new Product * [size];

    productArray[0] = new Product("Apples", 1.99);
    productArray[1] = new Product("Oranges", 2.49);
    productArray[2] = new Product("Bananas", 0.99);

    for (int i = 0; i < size; i++) {
        productArray[i]->print();
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        delete productArray[i];
    }
    delete[] productArray;

    cout << "Product array destroyed.\n";

    return 0;
}
