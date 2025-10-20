#include <iostream>

using namespace  std;

int main () {

    cout << "miles to km converter....\n\n";

    double miles = 0.00;

    cout << "enter number to convert from miles to km: ";
    cin >> miles;

    cout << "that is " << miles * 1.609 << " km.";

    return 0;
}
