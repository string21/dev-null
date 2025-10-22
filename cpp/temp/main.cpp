#include <iostream>
using namespace std;

/*
* Write a program that “bleeps” out words that you don’t like;
* that is, you read in words using cin and print them again on cout.
* If a word is among a few you have defined, you write out BLEEP instead of that word.
* Start with one “disliked word” such as
* string disliked = "Broccoli";
* When that works, add a few more.
*/

int main () {

    vector<string> words;

    vector<string> dislikedWords = {
        "red",
        "fail"
    };

    for (string temp; cin >> temp;) {
        words.push_back(temp);
    }

    bool isOK = true;
    for (string word : words) {
        for (string disliked : dislikedWords) {
            if (word ==  disliked) {
                isOK = false;
            }
        }

        if (isOK) {
            cout << word;
        } else {
            cout << "BLEEP";
        }
        isOK = true;
        cout << "\n";
    }

    return 0;

}