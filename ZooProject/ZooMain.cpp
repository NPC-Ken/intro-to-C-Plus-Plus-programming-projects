#include "Zoo.h"
#include <iostream>
using namespace std;

/*

If your Animal, Enclosure, and Zoo classes were created correctly, then
running this program should produce the output shown below. 
If it does not, take another look at your class functions.

--------------CORRECT OUTPUT--------------

The zoo contains:
3 Giraffe
1 Tiger
16 Flamingo
4 Elephant
2 Polar Bear

The zoo contains:
2 Dolphin
1 Manta Ray
10 Starfish

The zoo has the following enclosures:
Savannah
Jungle
Pond
Savannah
Arctic

The zoo has the following enclosures:
Pool
Large Tank
Large Tank

-------------END OF OUTPUT---------------
*/

int main() {
	// create a zoo with 5 enclosures
	Zoo zoo(5);

	// add animals/enclosures to the zoo directly
	zoo.addExhibit(Animal("Giraffe"), "Savannah", 3);
	zoo.addExhibit(Animal("Tiger"), "Jungle", 1);
	zoo.addExhibit(Animal("Flamingo"), "Pond", 16);

	// create new animals, add them to enclosures, then add them to the zoo
	Animal elephant("Elephant");
	Animal bear("Polar Bear");

	Enclosure field(elephant, "Savannah", 4);
	Enclosure pool(bear, "Arctic", 2);

	zoo.addExhibit(field);
	zoo.addExhibit(pool);

	// try adding more exhibits than the zoo can hold
	if (zoo.addExhibit(Animal("Camel"), "Desert", 5)) {
		cout << "ERROR: A zoo with space for 5 exhibits just added a 6th animal!" << endl
			<< "Check your addExhibit functions to make sure they don't add Enclosures "
			<< "beyond their maximum," << endl << "and that they return the correct "
			<< "boolean values!" << endl;
	}

	// create a new zoo with 5 enclosures
	Zoo aquarium(10);

	// add animals/enclosures to the aquarium
	// leave some spaces in the aquarium intentionally unfilled
	aquarium.addExhibit(Animal("Dolphin"), "Pool", 2);
	aquarium.addExhibit(Animal("Manta Ray"), "Large Tank", 1);
	aquarium.addExhibit(Animal("Starfish"), "Large Tank", 10);

	// display the animals in each zoo
	zoo.displayExhibits();
	cout << endl;

	aquarium.displayExhibits();
	cout << endl;

	// display the habitat enclosures that each zoo contains
	zoo.listHabitats();
	cout << endl;

	aquarium.listHabitats();
	cout << endl;

	return 0;
}