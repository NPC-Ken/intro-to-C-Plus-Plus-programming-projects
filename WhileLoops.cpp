#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    int myNum = rand() % 100 + 1;
    int guess;

    cout << "I've picked a number between 1 and 100." << endl;
    cout << "Try to guess what it is!" << endl;

    // Loop until the correct guess
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < myNum) {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > myNum) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed it!" << endl;
            break;
        }
    }

    return 0;
}
