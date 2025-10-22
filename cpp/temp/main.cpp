#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Write a program that reads a string from input and then,
 * for each character read, prints out the character and its integer value on a line.
 */

// the first 2 solutions are mine

int main () {

    string word = "another";

    // solution 1, explicit type conversion
    cout << "solution 1\n";
    for (char w : word) {
        cout << w << "\t" << (int) w << "\n";
    }

    // solution 2, add 0 to a char
    cout << "solution 2\n";
    for (char w : word) {
        cout << w << "\t" << w + 0 << "\n";
    }

    // this third solution is what chatgpt told me when i asked it  to give me a better more modern way to solve in using modern c++
    cout << "solution 3\n";
    for (char w : word) {
        cout << w << "\t" << static_cast<int>(w) << "\n";
    }

}