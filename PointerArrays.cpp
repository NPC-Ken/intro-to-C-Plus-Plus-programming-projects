#include <iostream>
using namespace std;

int findMode(int* arr, int size);
void printArray(int* arr, int size);

int main() {
    cout << "Ken Stewart\n\n";

    int list1[] = { 0, 1, 2, 2, 2, 2, 2, 3 };
    int list2[] = { 5, 6, 5, 4, 3, 6, 6, 5, 4, 5, 6 };
    int list3[] = { 10, 11, 12, 13, 14 };

    cout << "The first array is:\n";
    printArray(list1, 8);
    int mode1 = findMode(list1, 8);
    if (mode1 == -1) cout << "This array has no mode\n";
    else cout << "The mode is " << mode1 << "\n";

    cout << "\nThe second array is:\n";
    printArray(list2, 11);
    int mode2 = findMode(list2, 11);
    if (mode2 == -1) cout << "This array has no mode\n";
    else cout << "The mode is " << mode2 << "\n";

    cout << "\nThe third array is:\n";
    printArray(list3, 5);
    int mode3 = findMode(list3, 5);
    if (mode3 == -1) cout << "This array has no mode\n";
    else cout << "The mode is " << mode3 << "\n";

    return 0;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int findMode(int* arr, int size) {
    int maxCount = 0;
    int mode = -1;

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (*(arr + j) == *(arr + i)) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = *(arr + i);
        }
    }

    if (maxCount == 1) return -1;
    return mode;
}
