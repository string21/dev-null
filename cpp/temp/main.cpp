#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> primes = {};

    for(int i=2; i<=100; ++i) {

        bool isPrime = true;

        for(int p : primes) {
            if(i % p == 0) { // the main logic
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