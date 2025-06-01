#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
private:
    std::string species;

public:
    Animal();                       // sets species to "Empty"
    Animal(std::string newSpecies); // sets species to newSpecies
    std::string getSpecies() const; // returns species
};

#endif

