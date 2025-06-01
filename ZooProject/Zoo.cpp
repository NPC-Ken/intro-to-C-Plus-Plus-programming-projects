#include "Zoo.h"
#include <iostream>

Zoo::Zoo(int max)
    : exhibits(nullptr), numExhibits(0), maxExhibits(max) {
    if (maxExhibits > 0)
        exhibits = new Enclosure[maxExhibits];
}

Zoo::~Zoo() {
    delete[] exhibits;
}

bool Zoo::addExhibit(Animal newExhibit, std::string newHabitat, int occupants) {
    if (numExhibits >= maxExhibits) return false;

    exhibits[numExhibits] = Enclosure(std::move(newExhibit),
        std::move(newHabitat),
        occupants);
    ++numExhibits;
    return true;
}

bool Zoo::addExhibit(Enclosure newExhibit) {
    if (numExhibits >= maxExhibits) return false;

    exhibits[numExhibits] = std::move(newExhibit);
    ++numExhibits;
    return true;
}

void Zoo::displayExhibits() const {
    if (numExhibits == 0) {
        std::cout << "The zoo is currently empty.\n";
        return;
    }
    std::cout << "The zoo contains:\n";
    for (int i = 0; i < numExhibits; ++i) {
        std::cout << exhibits[i].getNumberOfOccupants() << ' '
            << exhibits[i].getAnimal().getSpecies() << '\n';
    }
    std::cout << '\n';
}

void Zoo::listHabitats() const {
    if (numExhibits == 0) {
        std::cout << "The zoo is currently empty.\n";
        return;
    }
    std::cout << "The zoo has the following enclosures:\n";
    for (int i = 0; i < numExhibits; ++i) {
        std::cout << exhibits[i].getHabitat() << '\n';
    }
    std::cout << '\n';
}
