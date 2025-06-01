// Kenneth Stewart

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int getScore();
float calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main()
{
    cout << "Kenneth Stewart" << endl;

    int score1 = getScore();
    int score2 = getScore();
    int score3 = getScore();
    int score4 = getScore();
    int score5 = getScore();

    float average = calcAverage(score1, score2, score3, score4, score5);

    cout << fixed << setprecision(2);
    cout << "Average of the four highest scores: " << average << endl;

    return 0;
}

// Gets and validates a single test score
int getScore()
{
    int score;
    do {
        cout << "Enter a test score (0-100): ";
        cin >> score;
        if (score < 0 || score > 100)
            cout << "Invalid score. Try again." << endl;
    } while (score < 0 || score > 100);

    return score;
}

// Finds and returns the lowest of the 5 scores
int findLowest(int a, int b, int c, int d, int e)
{
    int lowest = a;

    if (b < lowest) lowest = b;
    if (c < lowest) lowest = c;
    if (d < lowest) lowest = d;
    if (e < lowest) lowest = e;

    return lowest;
}

// Calculates and returns the average of the highest 4 scores
float calcAverage(int a, int b, int c, int d, int e)
{
    int lowest = findLowest(a, b, c, d, e);
    float sum = a + b + c + d + e - lowest;
    return sum / 4.0;
}