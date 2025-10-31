#include <iostream>
using namespace std;

double ctok(double c);
double ktoc(double k);
void error(string errorMessage);
void expect(bool precondition, string errorMessage);

int main() {
    try {

        cout << "select one of the following: \n";
        cout << "1. convert celsius to kelvin\n";
        cout << "2. convert kelvin to celsius\n";
        cout << "enter your choice:  ";
        int userChoice = 0;
        cin >> userChoice;

        if (userChoice == 1) {
            cout << "enter temp in celsius to covert to kelvin:  ";
            double c = 0;
            cin >> c;
            double k = ctok(c);
            cout << k << " Kelvin\n";
        } else if (userChoice == 2) {
            cout << "enter temp in kelvin to covert to ceosius:  ";
            double k = 0;
            cin >> k;
            double c = ktoc(k);
            cout << c << " Celsius\n";
        } else {
            error("Not a valid choice...");
        }


    } catch (runtime_error& e) {
        cerr << "ERROR: " << e.what();
    } catch (...) {
        cerr << "ERROR: Unknown exception has been spotted...";
    }
}

double ctok(double c) { // converts Celsius to Kelvin
    expect(c >= -273.25, "bad arg for function ... celsius value should be greater than or equal to -273.25!");
    double k = c + 273.25;
    return k;
}

double ktoc(double k) { // converts Kelvin to Celsius
    expect(k >= 0, "bad arg for function ... kelvin value should be greater equal to 0 (zero)!");
    double c = k - 273.25;
    return c;
}

void error(string errorMessage) {
    throw runtime_error{errorMessage};
}

void expect(bool precondition, string errorMessage) {
    if (!precondition) error(errorMessage);
}