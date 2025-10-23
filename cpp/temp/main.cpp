#include <iostream>
using namespace std;

/*
*
* Make a vector holding the ten string values "zero", "one", . . . "nine".
* Use that in a program that converts a digit to its corresponding spelled-out value;
* e.g., the input 7 gives the output seven. Have the same program, using the same input loop,
* convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7.
*/

// this is solution2 which is cleaner

int main() {

    vector<string> nums = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };


    while (true) {

        cout << "enter number to convert to string (0 to 9 only): ";
        int temp = -1;
        cin >> temp;

        if (!cin.good()) break;

        if (temp > nums.size()-1 || temp < 0) {
            cout << "invalid input";
        } else {
            cout << "that converts to " << nums[temp];
        }

        cout << "\n";

    }
}