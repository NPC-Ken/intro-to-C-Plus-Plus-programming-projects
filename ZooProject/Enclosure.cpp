#include "Enclosure.h"

Enclosure::Enclosure()
    : exhibit(), habitat("Empty"), numOccupants(0) {
}

Enclosure::Enclosure(Animal newExhibit, std::string newHabitat, int occupants)
    : exhibit(std::move(newExhibit)),
    habitat(std::move(newHabitat)),
    numOccupants(occupants) {
}

void Enclosure::setAnimal(Animal newExhibit) {
    exhibit = std::move(newExhibit);
}

void Enclosure::setHabitat(std::string newHabitat) {
    habitat = std::move(newHabitat);
}

void Enclosure::setNumberOfOccupants(int newNumber) {
    numOccupants = newNumber;
}

Animal Enclosure::getAnimal() const {
    return exhibit;
}

std::string Enclosure::getHabitat() const {
    return habitat;
}

int Enclosure::getNumberOfOccupants() const {
    return numOccupants;
}
