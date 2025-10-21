#include <iostream>
using namespace std;

// testing out vector for the first time

int main () {

    vector<int> age_of_participants = {1, 2, 4, 8};

    for (int age : age_of_participants)
        cout << age;

    return 0;
}
