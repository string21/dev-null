#include <iostream>
using namespace std;

/*
 * chapter drill
 */

int main () {

    double num1 = 0.00;
    double num2 = 0.00;
    cout << "enter two numbers (doubles):\n";
    while (cin >> num1 >> num2) {
            cout << num1 << "\t" << num2 << "\n";

            if (num1 == num2) {
                cout << "\nthe numbers are equal";
            } else if (num1 > num2) {
                cout << "\nthe larger value is: " << num1;
                cout << "\nthe smaller value is: " << num2;
            } else {
                cout << "\nthe larger value is: " << num2;
                cout << "\nthe smaller value is: " << num1;
            }

            if (abs(num1 - num2) < (1.00/100) && num1 != num2) {
                cout << "\nthey are almost equal";
            }
    }

}