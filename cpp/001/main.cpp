#include <iostream>
using namespace std;

constexpr double y = 1;
constexpr double k = 2;
constexpr double p = 3;

double convertDollar(double dollar, char unit);

int main () {

    double dollar = 0;
    char unit;
    double result = 0;

    cout << "enter dollar to convert and unit separated by whitespace: ";

    cin >> dollar >> unit;

    result = convertDollar(dollar, unit);

    if (result)
        cout << dollar << " USD is " << result << unit;
    else
        cout << "check your input";



    return 0;
}

double convertDollar(double dollar, char unit) {
    if (unit == 'y')
        return dollar * y;
    else if (unit == 'k')
        return dollar * k;
    else if (unit == 'p')
        return dollar * p;
    return 0;
}