#include <iostream>
#include <string>
using namespace std;

class Dog {
private:
    string name;
    string breed;
    int age;

public:
    // Constructor
    Dog(string dogName, string dogBreed, int dogAge) {
        name = dogName;
        breed = dogBreed;
        age = dogAge;
    }

    // Accessor for name
    string getName() {
        return name;
    }

    // Mutator for age
    void setAge(int newAge) {
        age = newAge;
    }
};

int main() {
    // Create a Dog object
    Dog myDog("Buddy", "Labrador", 3);

    // Update the dog's age
    myDog.setAge(4);

    // Output the dog's name
    cout << "Dog's name: " << myDog.getName() << endl;

    return 0;
}
