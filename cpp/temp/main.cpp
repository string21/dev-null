#include <iostream>
using namespace std;

int main () {

    vector<int> age_of_participants(5);

    age_of_participants[0] = 22;

    cout << age_of_participants.at(5);

    return 0;
}
