#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int> numSet);

int main() {
    vector<int> numSet = {
        1,2,3,4,5,6,7,8,9,9,9
    };

    vector<int> counter(getMax(numSet)+1, 0); // this could be improved with map but not familiar with that yet

    for(int i = 0; i < numSet.size(); ++i) {
        int temp = numSet[i];
        counter[temp] += 1;
    }

    for(int i = 0; i < counter.size(); i++) {
        cout << i << " = " << counter[i];
        if (counter[i] == getMax(counter)) { // compute getmax outside loop to improve performance
            cout << " ---->> this is our mode, we have " << counter[i] << " instances of " << i;
        }
        cout << "\n";
    }
}

int getMax(vector<int> numSet) {
    int max = numSet[0];
    for(int n : numSet) {
        if (n > max) {
            max = n;
        }
    }
    return max;
}