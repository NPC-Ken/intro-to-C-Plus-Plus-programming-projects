#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_QUESTIONS = 15;

// Function prototypes
void loadCorrectAnswers(char[], const int);
void getStudentAnswers(char[], const int);
void gradeQuiz(const char[], const char[], const int);

int main() {
    cout << "Ken Stewart" << endl; // <-- Replace with your actual name

    char correctAnswers[NUM_QUESTIONS];
    char studentAnswers[NUM_QUESTIONS];

    loadCorrectAnswers(correctAnswers, NUM_QUESTIONS);
    getStudentAnswers(studentAnswers, NUM_QUESTIONS);
    gradeQuiz(correctAnswers, studentAnswers, NUM_QUESTIONS);

    return 0;
}

void loadCorrectAnswers(char correctAnswers[], const int size) {
    ifstream inputFile("CorrectAnswers.txt");
    if (!inputFile) {
        cout << "Error opening CorrectAnswers.txt file." << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        inputFile >> correctAnswers[i];
    }

    inputFile.close();
}

void getStudentAnswers(char studentAnswers[], const int size) {
    cout << "------Test taking program------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter your answer to question " << (i + 1) << ": ";
        cin >> studentAnswers[i];
        studentAnswers[i] = toupper(studentAnswers[i]);

        // Input validation
        while (studentAnswers[i] != 'A' && studentAnswers[i] != 'B' &&
            studentAnswers[i] != 'C' && studentAnswers[i] != 'D') {
            cout << "Please only enter A, B, C, or D." << endl;
            cout << "Enter your answer to question " << (i + 1) << ": ";
            cin >> studentAnswers[i];
            studentAnswers[i] = toupper(studentAnswers[i]);
        }
    }
}

void gradeQuiz(const char correctAnswers[], const char studentAnswers[], const int size) {
    int correctCount = 0;

    cout << endl << "*** Quiz Results ***" << endl;

    for (int i = 0; i < size; i++) {
        if (studentAnswers[i] != correctAnswers[i]) {
            cout << "Missed question #" << (i + 1)
                << " - Student's answer: " << studentAnswers[i]
                << " Correct answer: " << correctAnswers[i] << endl;
        }
        else {
            correctCount++;
        }
    }

    double percentage = (static_cast<double>(correctCount) / size) * 100;

    cout << "Number of correct answers: " << correctCount << endl;
    cout << fixed << setprecision(2);
    cout << "Percentage answered correctly: " << percentage << "%" << endl;
}
