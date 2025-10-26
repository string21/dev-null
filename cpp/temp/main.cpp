#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string getMin(vector<string> list);
string getMax(vector<string> list);
string getMode(vector<string> unique, vector<int> modeCounter);

int main() {

    vector<string> words = {
        "xenon", "omega", "alpha", "beta", "gamma", "lambda", "sigma", "zeta", "alpha", "alpha",
        "beta", "omega", "theta", "lambda", "lambda", "lambda", "gamma", "sigma", "zulu", "zulu", "zulu"
    };



    vector<string> unique = {};

    for(int i = 0; i < words.size(); ++i) {
        bool isUnique = true;

        for (string u : unique) {
            if (u == words[i]) {
                isUnique = false;
            }
        }

        if (isUnique) {
            unique.push_back(words[i]);
        }
    }

    vector<int> modeCounter(unique.size(), 0);

    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < unique.size(); ++j) {
            if (unique[j] == words[i]) {
                ++modeCounter[j];
            }
        }
    }



    cout << "min (alphabetically) is " << getMin(words) << "\n";
    cout << "max (alphabetically) is " << getMax(words) << "\n";
    cout << "mode is " << getMode(unique, modeCounter) << "\n";

}

string getMode(vector<string> unique, vector<int> modeCounter) {
    int max = modeCounter[0];
    int maxIndex = 0;

    // cout << "max is initialized to " << max << "\n";

    for (int i = 0; i < modeCounter.size(); i++) {
        //cout << "checking modeCounter index " << i << " -- " << modeCounter[i] << "\n";
        if (max < modeCounter[i]) {
            // cout << "max is being replaced..." << "\n";
            max = modeCounter[i];
            maxIndex = i;
        }
    }

    // cout << "final max index is " << maxIndex << "\n";

    for (int i = 0; i < modeCounter.size(); i++) {
         // cout << unique[i] << " count is " << modeCounter[i] << "\n";
        // if (modeCounter[i] == max) return unique[i];
    }
    return unique[maxIndex];
}

string getMin(vector<string> list) {
    string min = list[0];
    for (string l : list) {
        if (l < min) {
            min = l;
        }
    }
    return min;
}

string getMax(vector<string> list) {
    string max = list[0];
    for (string l : list) {
        if (l > max) {
            max = l;
        }
    }
    return max;
}