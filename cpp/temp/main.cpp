#include <iostream>
using namespace std;

void error(string s);

int main() {
    try {
        int num = 0;
        cout << "enter integer:  ";
        cin >> num;

        if (!cin) {
            // cout << "no throw here...\n";
            error("bad cin input...");
        }

        cout << "input is: " << num << "\n";

        vector<int> numCollection;
        numCollection.push_back(21);
        numCollection.push_back(42);
        cout << "first number is " << numCollection[0] << "\n";
        cout << "second number is " << numCollection[1] << "\n";
        // instead of relying on .at() to throw the out of range
        // im going to manually test myself throw manually which gives me
        // option to send a custom message
        int temp = 2;
        if (temp >= numCollection.size())
            throw out_of_range{"out of bounds vector"};
        cout << "third number is " << numCollection.at(temp) << "\n";

    } catch (runtime_error& e) {
        cerr << "INPUT ERROR: " << e.what() << "\n";
    } catch (out_of_range& e) {
        cerr << "RANGE ERROR: " << e.what() << "\n";
    }
}
void error(string s) {
    throw runtime_error(s);
}