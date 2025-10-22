#include <iostream>
#include <algorithm>
using namespace std;

/*
 * fix the median for even number of inputs "drill"
 */

int main () {

    cout << "enter nubmers or doubles, terminate by entering non-number:\n";

    vector<double> numbers;

    for (double temp; cin >> temp;) {
        numbers.push_back(temp);
    }

    cout << "\nthe numbers user entered:\n";
    for (double n : numbers ) {
        cout << n << "  ";
    }

    ranges::sort(numbers);

    if (numbers.size()%2 == 0) {
        cout << "even\n";
        double temp = numbers[numbers.size()/2] + numbers[(numbers.size()/2)-1];
        temp /= 2;
        cout << "median is " << temp;

    } else {
        cout << "oddn\n";
        cout << "median is " << numbers[numbers.size()/2];
    }

}