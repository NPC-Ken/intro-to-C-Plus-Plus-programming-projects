// Ken Stewart
#include <iostream>
using namespace std;

// Function prototypes
void bubbleSort(float* scores, int size);
float findAverage(float* scores, int size);

int main() {
    int numScores;
    float* scores = nullptr;

    // Ask user for number of scores
    cout << "Enter the number of scores: ";
    cin >> numScores;

    // Dynamically allocate array
    scores = new float[numScores];

    // Read scores into the array
    for (int i = 0; i < numScores; i++) {
        cout << "Enter score #" << (i + 1) << ": ";
        cin >> scores[i];
    }

    // Calculate and display average
    float average = findAverage(scores, numScores);
    cout << "Average score: " << average << endl;

    // Sort the scores
    bubbleSort(scores, numScores);

    // Display sorted scores
    cout << "Sorted scores in ascending order:\n";
    for (int i = 0; i < numScores; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] scores;

    return 0;
}

// Function to calculate average
float findAverage(float* scores, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / size;
}

// Bubble sort function
void bubbleSort(float* scores, int size) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < size - 1; i++) {
            if (scores[i] > scores[i + 1]) {
                float temp = scores[i];
                scores[i] = scores[i + 1];
                scores[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}