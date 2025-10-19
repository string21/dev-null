#include <iostream>

using namespace std;

//test concatenation and if

int main () {

    string string1;
    string string2;

    cout << "enter your first and second name separated by whitespace: ";
    cin >> string1 >> string2;

    if (string1 == string2) {
        cout << "you entered the same name twice";
    }

    if (string1 < string2) {
        cout << string1 << " is alphabethically before " << string2;
    }

    if (string1 > string2) {
        cout << string1 << " is alphabethically after " << string2;
    }

}
