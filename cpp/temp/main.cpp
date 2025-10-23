#include <iostream>
using namespace std;

/*
 * convert in both directions
 */

int main() {

    vector<string> nums = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };

    while (true) {

        cout << "enter number to convert to string (0 to zero) or vice versa (nine to 9), type exit to quit: ";
        string input;
        getline(cin, input);

        if (!cin.good() || input == "exit") break;

        bool foundInVector = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (input == nums[i]) {
                cout << i;
                foundInVector = true;
                break;
            }

            if (input == to_string(i)) {
                cout << nums[i];
                foundInVector = true;
                break;
            }
        }

        if (!foundInVector) {
            cout << "invalid input!\n";
        }

        cout << "\n";

    }
}