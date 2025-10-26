#include <iostream>
#include <vector>
using namespace std;
int main() {
    int limit = 100;
    vector<bool> isPrime(limit+1, true); // so we get index 0 to 100 = 101 items
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= limit; ++i) {
        if (isPrime[i]) {
            for(int j = i*i; j <= limit; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 0; i <= limit; ++i) {
        if (isPrime[i]) {
            cout << i << "  ";
        }
    }

}