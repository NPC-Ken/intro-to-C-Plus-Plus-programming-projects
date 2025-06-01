#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;

public:
    Product(string name, double price);
    void setName(string name);
    void setPrice(double price);
    string getName() const;
    double getPrice() const;
    void print() const;
};

#endif