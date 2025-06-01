#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(string name, double price) {
    this->name = name;
    this->price = price;
}

void Product::setName(string name) {
    this->name = name;
}

void Product::setPrice(double price) {
    this->price = price;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::print() const {
    cout << name << " $" << price;
}