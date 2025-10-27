#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names;
    vector<int> scores;

    while(true) {
        string tempName;
        int tempScore;
        cout << "enter a name score pair (separate by space):  ";
        cin >> tempName >> tempScore;

        if(!cin.good() || (tempName == "NoName" && tempScore == 0)) break;

        bool isDup = false;
        for(string n : names) {
            if(tempName == n) {
                cout << "*** Error: that name already exists! ***\n";
                isDup = true;
            }
        }

        if(isDup) break;

        names.push_back(tempName);
        scores.push_back(tempScore);
    }

    for(int i = 0; i < names.size(); ++i) {
        cout << names[i] << "  " << scores[i] << "\n";
        // if(i != names.size()-1) cout << "\n";
    }

    // search name feature -- return score or no name found

    cout << "*** search for score by typing the name ***\n";
    while(true) {
        cout << "search query or 'exit' to quit:  ";
        string query = {};
        cin >> query;

        if(!cin.good() || query == "exit") break;

        bool isFound = false;
        for(int i = 0; i < names.size(); ++i) {
            if(query == names[i]) {
                isFound = true;
                cout << "----------------------------->> score for " << names[i] << " is " << scores[i] << "\n";
                break;
            }
        }

        if (isFound == true) {
            break;
        } else {
            cout << "*** name not found ***\n";
        }
    }

    // search score feature -- return names with that score or no score found

    cout << "*** search by score ***\n";
    while(true) {
        cout << "enter score or 'exit' to quit:  ";
        string query = {};
        cin >> query;

        if (!cin.good() || query == "exit") break;

        vector<string> namesWithThatScore = {};
        bool isFound = false;
        for (int i = 0; i < names.size(); ++i) {
            if (stoi(query) == scores[i]) {
                isFound = true;
                namesWithThatScore.push_back(names[i]);
            }
        }

        if (isFound) {
            for (string name : namesWithThatScore) {
                cout << name << "\n";
            }
            break;
        } else {
            cout << "*** score not found ***\n";
        }
    }
}