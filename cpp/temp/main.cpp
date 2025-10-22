#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    vector<string> words;

    for(string temp; cin>>temp;)
        words.push_back(temp);

    cout << "Number of words:" << words.size() << '\n';

    ranges::sort(words); // sort the words

    for (int i = 0; i<words.size(); ++i) {
        if (i==0 || words[i-1] != words[i])
            cout << words[i] << "\n";
    }

}