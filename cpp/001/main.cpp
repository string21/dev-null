#include <iostream>

using namespace std;

int main () {

    cout << "enter floating-point number here: ";
    double n = 0;
    cin >> n;
    cout << "n == " << n << "\n"
         << "n+1 == " << n+1 << "\n"
         << "three times n == " << 3*n << "\n"
         << "twice n == " << n+n << "\n"
         << "n squared == " << n*n << "\n"
         << "half of n == " << n/2 << "\n"
         << "square root of n == " << sqrt(n) << "\n";
}

// the notation for = is == instead of = ... because plain = is for assignment