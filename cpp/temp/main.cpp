#include <iostream>
#include <vector>
using namespace std;

int main() {

    cout << "enter the number of primes to print: ";
    int count = {};
    cin >> count;

    vector<int> primes;


    for (int i=2; primes.size() < count; ++i) {
        bool isPrime = true;

        for (int p : primes) {
            // this is optional, no need ot check past the sqrt of i here
            if (p*p > i) break;

            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }


    }

    for (int p : primes) {
        cout << p << "  ";
    }

}