#include <iostream>
using namespace std;

// Formulas:
// Celsius to Fahrenheit: $F = (C \times \frac{9}{5}) + 32$
// Fahrenheit to Celsius: $C = (F - 32) \times \frac{5}{9}$

// ill make sure to break things into smaller functions and try to handle all legal and illegal inputs

void printMenu();
short getUserMenuChoice();
void processChoice(short choice);
void expect (bool validityCheck, string e);
void error(string e);

int main() {
    try {
        printMenu();
        short choice = getUserMenuChoice();
        processChoice(choice);
    } catch (runtime_error& e) {
        cerr << "ERROR:  " << e.what();
    } catch (...) {
        cout << "Opps...... unknown error!";
    }
}

int getTemperature() {
    cout << "enter the temperature: ";
    int temp = 0;
    cin >> temp;
    expect(cin.good(), "invalid temperature value...");
    return temp;
}

void print_c_to_fahrenheit(double temp) {
    cout << ((temp * 9) / 5) + 32;
}

void print_f_to_celsius(double temp) {
    cout << ((temp - 32) * 5)/9;
}

void processChoice(short choice) {
    int temperature = getTemperature();
    switch (choice) {
        case 1:
            print_c_to_fahrenheit(temperature);
            break;
        case 2:
            print_f_to_celsius(temperature);
            break;
    }
}

short getUserMenuChoice() {
    short choice = 0;
    cin >> choice;
    expect(cin.good() && choice >= 1 && choice <= 2, "invalid user choice...");
    return choice;
}

void printMenu() {
    cout << "\n*** choose what you want to do today ***\n"
         << "1. convert to fahrenheit \n"
         << "2. convert to celsius \n"
         << "enter your choice:  ";
}

void error(string e) {
    throw runtime_error {e};
}

void expect (bool validityCheck, string e) {
    // test if the function argument(s) are any good
    if (!validityCheck) error(e);
}