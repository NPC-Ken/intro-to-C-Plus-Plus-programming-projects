#ifndef RECEIPT_H
#define RECEIPT_H

#include "Product.h"

class Receipt {
private:
    Product** productList;
    int* quantities;
    int length;
    int items;

public:
    Receipt(int length);
    ~Receipt();
    bool purchase(string name, double price, int quantity);
    void print() const;
};

#endif
