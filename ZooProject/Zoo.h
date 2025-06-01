#ifndef ZOO_H
#define ZOO_H

#include "Enclosure.h"
#include <string>

class Zoo {
private:
    Enclosure* exhibits;
    int        numExhibits;
    int        maxExhibits;

public:
    explicit Zoo(int max);  // allocates exhibits array
    ~Zoo();                 // frees exhibits array

    bool addExhibit(Animal newExhibit, std::string newHabitat, int occupants);
    bool addExhibit(Enclosure newExhibit);

    void displayExhibits() const;
    void listHabitats()    const;
};

#endif
