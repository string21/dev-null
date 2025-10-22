#include <algorithm>
#include <iostream>
using namespace std;

int main () {

    vector<double> temps;

    for (double temp; cin >> temp;)
        temps.push_back(temp);

    for (double t : temps)
        cout << t << "  ";

    // compute mean
    double total = 0;
    for (double t : temps)
        total += t;
    cout << "mean is " << total/temps.size() << "\n";

    // compute median
    ranges::sort(temps);
    cout << "median is " << temps[temps.size()/2];



    return 0;
}
