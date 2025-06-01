#include "Receipt.h"
#include <iostream>
using namespace std;

Receipt::Receipt(int length) {
    this->length = length;
    this->items = 0;
    productList = new Product * [length];
    quantities = new int[length];
    for (int i = 0; i < length; ++i) {
        productList[i] = nullptr;
        quantities[i] = 0;
    }
}

Receipt::~Receipt() {
    for (int i = 0; i < items; ++i) {
        delete productList[i];
    }
    delete[] productList;
    delete[] quantities;
    cout << "Receipt destroyed\n";
}

bool Receipt::purchase(string name, double price, int quantity) {
    if (items >= length) return false;

    productList[items] = new Product(name, price);
    quantities[items] = quantity;
    items++;
    return true;
}

void Receipt::print() const {
    for (int i = 0; i < items; ++i) {
        productList[i]->print();
        cout << " x" << quantities[i] << endl;
    }
}