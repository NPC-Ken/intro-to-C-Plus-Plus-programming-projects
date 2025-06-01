// Ken Stewart

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Variables
	string name;
	string campus;
	int units;
	// First line will cause the program to output some text; in this case it is giving the user some instructions.
	// The second line will accept text typed from the user and store it in the name variable.
	cout << "Please enter your name: ";
	getline(cin, name);
	// Asking the user for the name of their campus.
	cout << "Please enter the name of your campus: ";
	getline(cin, campus);
	// Second line is different because we are getting a number this time instead of text.
	cout << "Please enter the amount of units you are taking this semester: ";
	cin >> units;
	// These four lines take the data that the user typed in and show it in some nice formatting.
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Campus: " << campus << endl;
	cout << "Units: " << units << endl;
	// This return line signals to the operating system that the program is finished running, and successful.
	return 0;
}