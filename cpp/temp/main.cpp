#include <iostream>
using namespace std;

/*
* Write a program to play a numbers guessing game.
* The user thinks of a number between 1 and 100 and your program asks questions
* to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”).
* Your program should be able to identify the number after asking no more than seven questions.
*/

// so this is solved by using binary search, i will try to implement that in code

int main() {
    int low = 1;
    int high = 100;

    cout << "hey user, guess a number from " << low << " to " << high << ": ";


    int guess = {};
    char playerInput = {};

    while (low != high) {

        guess = low + (high - low) / 2;

        cout << "\ncurrent low(" << low << ") and current high(" << high << ")";
        cout << "\nis the number <= " << guess << "? ('y' or 'n'): ";
        cin >> playerInput;
        cout << "\n";

        if (playerInput == 'y') {
            cout << "you choose y";
            high = guess;
        } else if (playerInput == 'n') {
            cout << "you chose n";
            low = guess + 1;
        } else {
            cout << "y or n only!";
            continue;
        }
    }

    cout << "\n\nyou got it, it's " << low;

}
