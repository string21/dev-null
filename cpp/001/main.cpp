#include <iostream>

using namespace  std;

int main () {

    cout << "enter number 1 and number 2 separated by whitespace: ";
    double num1 = 0;
    double num2 = 0;

    cin >> num1 >> num2;

    if (num1 > num2) cout << num1 << " is larger than " << num2;
    else if (num1 < num2) cout << num2 << " is larger than " << num1;
    else cout << "they are equal";
    cout << "\n";

    cout << "the difference is " << num1 - num2 << "\n";
    cout << "the product is " << num1 * num2 << "\n";
    cout << "ratio is " << num1 / num2;
    return 0;
}
