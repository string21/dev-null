#include <iostream>
#include <algorithm>
using namespace std;

/*
* Read a sequence of double values into a vector.
* Think of each value as the distance between two cities along a given route.
* Compute and print the total distance (the sum of all distances).
* Find and print the smallest and greatest distance between two neighboring cities.
* Find and print the mean distance between two neighboring cities.
*/

int main () {
    vector<double> numbers;

    // get input
    for (double temp; cin >> temp;) {
        numbers.push_back(temp);
    }

    // print the inputs
    for (double n : numbers) {
        cout << n << "  ";
    }

    // get total distance
    double total {};
    for (int i = 0; i < numbers.size(); ++i) {
        total += numbers.at(i);
    }
    cout << "the total is " << total << "\n\n";

    vector<double> distances;
    for (int i = 0; i < numbers.size()-1; ++i) {
            double tempDistance {};
            tempDistance = abs(numbers.at(i) - numbers.at(i+1));
            distances.push_back(tempDistance);
    }

    for (double d : distances) {
        cout << d << "  ";
    }
    cout << "\n\n";

    double smallest = distances.at(0);
    double largest = distances.at(0);

    for (int i = 0; i < distances.size(); ++i) {
        if (distances.at(i) > largest) {
            largest = distances.at(i);
        }

        if (distances.at(i) < smallest) {
            smallest = distances.at(i);
        }
    }

    cout << "smallest is " << smallest << "\n";
    cout << "largest is " << largest << "\n";

}