#include <iostream>
using namespace std;

void growList(int* list[], int* listSize, int numItems, int howMuch) {
    int newSize = *listSize + howMuch;
    int* newList = new int[newSize];
    for (int i = 0; i < numItems; i++) {
        newList[i] = (*list)[i];
    }
    delete[] * list;
    *list = newList;
    *listSize = newSize;
}

void shrinkList(int* list[], int* listSize, int numItems, int howMuch) {
    if (*listSize - howMuch < 1) return;
    int newSize = *listSize - howMuch;
    int* newList = new int[newSize];
    for (int i = 0; i < numItems; i++) {
        newList[i] = (*list)[i];
    }
    delete[] * list;
    *list = newList;
    *listSize = newSize;
}

void addElement(int* list[], int* listSize, int* numItems, int element) {
    if (*numItems == *listSize) {
        growList(list, listSize, *numItems, 10);
    }
    (*list)[*numItems] = element;
    (*numItems)++;
}

bool removeElement(int* list[], int* listSize, int* numItems, int element) {
    for (int i = 0; i < *numItems; i++) {
        if ((*list)[i] == element) {
            for (int j = i; j < *numItems - 1; j++) {
                (*list)[j] = (*list)[j + 1];
            }
            (*numItems)--;
            if (*numItems < *listSize / 2) {
                shrinkList(list, listSize, *numItems, *listSize / 2);
            }
            return true;
        }
    }
    return false;
}

int main() {
    int* list = new int[10];
    int listSize = 10;
    int numItems = 0;

    cout << "ADDING NUMBERS TO LIST:" << endl;
    for (int i = 1; i <= 50; i++) {
        addElement(&list, &listSize, &numItems, i * 2);
        cout << "list[" << i - 1 << "] = " << list[i - 1] << "; "
            << "listSize = " << listSize << "; numItems = " << numItems << endl;
    }

    cout << endl << "REMOVING NUMBERS FROM LIST:" << endl;
    for (int i = 4; i <= 100; i += 4) {
        bool success = removeElement(&list, &listSize, &numItems, i);
        if (success) {
            cout << "Removed " << i << "; "
                << "listSize = " << listSize << "; numItems = " << numItems << endl;
        }
        else {
            cout << "ERROR - failed to remove " << i << " from the array" << endl;
        }
    }

    for (int i = 3; i <= 100; i += 3) {
        bool success = removeElement(&list, &listSize, &numItems, i);
        if (success) {
            cout << "Removed " << i << "; "
                << "listSize = " << listSize << "; numItems = " << numItems << endl;
        }
        else {
            if (i % 2 == 0 && i % 4 != 0) {
                cout << "ERROR - failed to remove " << i << " from the array" << endl;
            }
        }
    }

    cout << endl << "FINAL ARRAY: listSize = " << listSize << "; numItems = " << numItems << endl;
    for (int i = 0; i < numItems; i++) {
        cout << list[i] << endl;
    }

    delete[] list;
    return 0;
}
