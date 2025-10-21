#include <iostream>
using namespace std;

/*
 * Implement square() without using the multiplication operator;
 * that is, do the x*x by repeated addition (start a variable result at 0 and add x to it x times).
 * Then run some version of “the first program” using that square().
 */

int square(int x);

int main () {

    cout << "enter a number to square: ";
    int num = 0;

    cin >> num;

    cout << "the square of " << num << " is " << square(num) << "\n";

    return 0;
}

int square(int x) {
    int total = 0;

    for (int i = 0; i < x; ++i) {
        total += x;
    }

    return total;
}