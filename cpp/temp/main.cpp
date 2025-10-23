#include <iostream>
using namespace std;

/*
*
* SIMPLE CALCULATOR
*
* Write a program that performs as a very simple calculator.
* Your calculator should be able to handle the four basic math operations –
* add, subtract, multiply, and divide – on two input values.
* Your program should prompt the user to enter three arguments:
* two double values and a character to represent an operation.
* If the entry arguments are 35.6, 24.1, and '+', the program output
* should be The sum of 35.6 and 24.1 is 59.7.
*/

string performCalculation(double x, double y, char symbol);

int main() {

    cout << "enter 2 double numbers and an operator like + - * /  ";
    double num1 = {};
    double num2 = {};
    char theOperator = {};

    cin >> num1 >> num2 >> theOperator;

    cout << performCalculation(num1, num2, theOperator);

}

string performCalculation(double x, double y, char symbol) {

    switch (symbol) {
        case '+':
            return "the sum of "s + to_string(x) + " and " + to_string(y) + " is " + to_string(x+y);
            break;
        case '-':
            return "the diff of "s + to_string(x) + " and " + to_string(y) + " is " + to_string(x-y);
            break;
        case '*':
            return "the product of "s + to_string(x) + " and " + to_string(y) + " is " + to_string(x*y);
            break;
        case '/':
            return "the quotient of "s + to_string(x) + " and " + to_string(y) + " is " + to_string(x/y);
            break;
        default:
            return "invalid input!";
    }
}