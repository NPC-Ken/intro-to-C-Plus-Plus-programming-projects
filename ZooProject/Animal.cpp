#include "Animal.h"

Animal::Animal() : species("Empty") {}

Animal::Animal(std::string newSpecies) : species(std::move(newSpecies)) {}

std::string Animal::getSpecies() const {
    return species;
}
