#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include <string>
#include "Animal.h"

class Enclosure {
private:
    Animal   exhibit;
    std::string habitat;
    int       numOccupants;

public:
    Enclosure();                                                // default
    Enclosure(Animal newExhibit, std::string newHabitat, int occupants);

    void   setAnimal(Animal newExhibit);
    void   setHabitat(std::string newHabitat);
    void   setNumberOfOccupants(int newNumber);

    Animal       getAnimal()           const;
    std::string  getHabitat()          const;
    int          getNumberOfOccupants() const;
};

#endif

