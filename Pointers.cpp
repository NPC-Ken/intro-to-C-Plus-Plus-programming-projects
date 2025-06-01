#include <iostream>
using namespace std;

int main() {
    double number1 = 1.11;
    double number2 = 2.22;
    double number3 = 3.33;

    double* pnumber;

    pnumber = &number1;
    cout << "The value of the pnumber 1 is: " << pnumber << endl;

    pnumber = &number2;
    cout << "The value of the pnumber 2 is: " << pnumber << endl;

    pnumber = &number3;
    cout << "The value of the pnumber 3 is: " << pnumber << endl;

    cout << *pnumber << endl;

    pnumber = &number2;
    *pnumber = 4.44;
    cout << number2 << endl;

    double* p1 = &number1;
    double* p2 = &number2;
    double* p3 = &number3;

    *p3 = *p1 + *p2;
    
    cout << number3 << endl;

    double list[] = { 0.1, 2.3, 4.5, 6.7, 8.9 };
    cout << list + 1 << endl;
    cout << *list + 1 << endl;
    cout << *(list + 1) << endl;

    void findHalf(double* number) {
        *number = *number / 2;
    }

    return 0;
}