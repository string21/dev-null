#include <iostream>
using namespace std;

int getActualNumber(string num, vector<string> numList);
string getOperationResult(int input1, int input2, string theOperator);

/*
 * Modify the “mini calculator” from exercise 6 to accept (just) single-digit numbers
 * written as either digits or spelled out.
 */

int main() {

    vector<string> numList = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    while (true) {
        string num1 = {};
        string num2 = {};
        string theOperator = {};

        cout << "enter two single-digit numbers (1, 2, one, two) and an operator (+ - * /), example: six 7 +    ";
        cin >> num1 >> num2 >> theOperator;

        if (!cin.good() || num1 == "exit") break;

        int input1 = getActualNumber(num1, numList);
        int input2 = getActualNumber(num2, numList);
        if (input1 != -1 && input2 != -1) {
            cout << getOperationResult(input1, input2, theOperator);
        } else {
            cout << "one of the inputs is invalid";
        }
        cout << "\n";
    }
}

// returns -1  if one of the numbers is invalid
int getActualNumber(string num, vector<string> numList) {
    for (int i = 0; i < numList.size(); ++i) {

        if (num == numList[i]) {
            return i;
        }

        if (num == to_string(i)) {
            return i;
        }

    }
    return -1;
}

string getOperationResult(int input1, int input2, string theOperator) {
    if (theOperator == "+") return "sum is "s + to_string(input1 + input2);
    if (theOperator == "-") return "difference is "s + to_string(input1 - input2);
    if (theOperator == "*") return "product is "s + to_string(input1 * input2);
    if (theOperator == "/") return "quotient is "s + to_string(input1 / input2);
    return "invalid operator";
}