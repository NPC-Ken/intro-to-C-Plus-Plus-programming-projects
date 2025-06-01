#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100; // Maximum number of entries allowed
string firstNames[MAX_SIZE]; // Array for first names
string lastNames[MAX_SIZE];  // Array for last names
int currentSize = 0;         // Tracks current number of entries

// Function Prototypes
void showMenu();                      // Display the main menu
void addName();                       // Add a new name to the roster
void deleteName();                    // Delete a name from the roster
void saveToFile();                    // Save the roster to a file
void readFromFile();                  // Load the roster from a file
void displayRoster();                 // Display the sorted roster
void deleteRoster();                  // Clear the roster
void sortRoster();                    // Sort roster alphabetically by last name then first name
bool nameExists(const string&, const string&); // Check if a name already exists
int binarySearch(const string&, const string&); // Binary search for a name

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 1: addName(); break;
        case 2: deleteName(); break;
        case 3: saveToFile(); break;
        case 4: readFromFile(); break;
        case 5: displayRoster(); break;
        case 6: {
            // Search for a name
            string first, last;
            cout << "Enter first name: ";
            getline(cin, first);
            cout << "Enter last name: ";
            getline(cin, last);
            sortRoster();
            int index = binarySearch(first, last);
            if (index != -1) cout << "Name found.\n";
            else cout << "Name not found.\n";
            break;
        }
        case 7: deleteRoster(); break;
        case 8: cout << "Exiting...\n"; break;
        default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}

void showMenu() {
    // Print main menu options
    cout << "\n--- Roster Manager ---\n";
    cout << "1. Add Name\n";
    cout << "2. Delete Name\n";
    cout << "3. Save Roster to File\n";
    cout << "4. Read Roster from File\n";
    cout << "5. Display Roster\n";
    cout << "6. Search Roster\n";
    cout << "7. Delete Entire Roster\n";
    cout << "8. Quit\n";
    cout << "Enter choice: ";
}

void addName() {
    // Add a name to the roster
    if (currentSize >= MAX_SIZE) {
        cout << "Roster is full.\n";
        return;
    }

    string first, last;
    cout << "Enter first name: "; getline(cin, first);
    cout << "Enter last name: "; getline(cin, last);

    if (nameExists(first, last)) {
        cout << "Name already exists.\n";
        return;
    }

    firstNames[currentSize] = first;
    lastNames[currentSize] = last;
    currentSize++;
    cout << "Name added successfully.\n";
}

void deleteName() {
    // Delete a specific name from the roster
    string first, last;
    cout << "Enter first name to delete: "; getline(cin, first);
    cout << "Enter last name to delete: "; getline(cin, last);

    sortRoster();
    int index = binarySearch(first, last);
    if (index == -1) {
        cout << "Name not found.\n";
        return;
    }

    for (int i = index; i < currentSize - 1; i++) {
        firstNames[i] = firstNames[i + 1];
        lastNames[i] = lastNames[i + 1];
    }
    currentSize--;
    cout << "Name deleted.\n";
}

void saveToFile() {
    // Save current roster to a file
    ofstream file("roster.txt");
    for (int i = 0; i < currentSize; i++) {
        file << firstNames[i] << "," << lastNames[i] << "\n";
    }
    file.close();
    cout << "Roster saved to file.\n";
}

void readFromFile() {
    // Read a roster from a file
    ifstream file("roster.txt");
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    currentSize = 0;
    string first, last;
    string line;
    while (getline(file, line) && currentSize < MAX_SIZE) {
        size_t comma = line.find(',');
        if (comma != string::npos) {
            first = line.substr(0, comma);
            last = line.substr(comma + 1);
            firstNames[currentSize] = first;
            lastNames[currentSize] = last;
            currentSize++;
        }
    }
    file.close();
    cout << "Roster loaded from file.\n";
}

void displayRoster() {
    // Sort and display the roster
    sortRoster();
    cout << "\n--- Roster ---\n";
    for (int i = 0; i < currentSize; i++) {
        cout << lastNames[i] << ", " << firstNames[i] << "\n";
    }
}

void deleteRoster() {
    // Clear all names from the roster
    currentSize = 0;
    cout << "Roster cleared.\n";
}

void sortRoster() {
    // Sort roster by last name, then first name
    for (int i = 0; i < currentSize - 1; i++) {
        for (int j = i + 1; j < currentSize; j++) {
            if (lastNames[j] < lastNames[i] ||
                (lastNames[j] == lastNames[i] && firstNames[j] < firstNames[i])) {
                swap(firstNames[i], firstNames[j]);
                swap(lastNames[i], lastNames[j]);
            }
        }
    }
}

bool nameExists(const string& first, const string& last) {
    // Check for exact duplicate in the roster
    for (int i = 0; i < currentSize; i++) {
        if (firstNames[i] == first && lastNames[i] == last) {
            return true;
        }
    }
    return false;
}

int binarySearch(const string& first, const string& last) {
    // Perform binary search for a name in the roster
    int low = 0, high = currentSize - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (lastNames[mid] == last) {
            if (firstNames[mid] == first) return mid;
            if (firstNames[mid] < first) low = mid + 1;
            else high = mid - 1;
        }
        else if (lastNames[mid] < last) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

