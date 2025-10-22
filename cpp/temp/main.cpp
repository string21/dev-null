#include <iostream>
#include <algorithm>
using namespace std;

/*
 * chapter drill
 */



int main () {

    double smallest {};
    double largest {};

    double temp {};
    string unit {};

    vector<double> validNums;
    vector<string> validUnits;

    bool isFirstLoop = true;

    while (cin >> temp >> unit) {

        if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft") {
            validNums.push_back(temp);
            validUnits.push_back(unit);
        } else break;

        if (isFirstLoop) {
            smallest = temp;
            largest = temp;
            isFirstLoop = false;
        }

        if (temp < smallest) smallest = temp;
        if (temp > largest) largest = temp;

        cout << "\nsmallest so far is " << smallest;
        cout << "\nlargest so far is " << largest;
        cout << "\n\n";

    }

    vector<double> numsInMeters;
    double tempOnly = 0.00;
    for (int i = 0; i < validUnits.size(); ++i) {
        if (validUnits[i] == "m") {
            tempOnly = validNums[i];
        }

        if (validUnits[i] == "cm") {
            tempOnly = validNums[i]/100;
        }

        if (validUnits[i] == "in") {
            tempOnly = (validNums[i]*2.54)/100;
        }

        if (validUnits[i] == "ft") {
            tempOnly = (validNums[i]*12*2.54)/100;
        }

        numsInMeters.push_back(tempOnly);
    }

    double total = 0.00;
    for (double x : numsInMeters) {
        total += x;
    }

    ranges::sort(numsInMeters);

    cout << "the total is " << total << " in meters for the following numbers: \n";

    for (double x : numsInMeters) {
        cout << x << "m  ";
    }


}