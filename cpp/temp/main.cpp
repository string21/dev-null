#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> someInt(4);

    someInt[0] = 12;
    someInt[1] = 62;
    someInt[2] = 34;
    someInt[3] = 78;




    for (int si : someInt) {

        cout << "num from loop is " << si << "\n";

    }

    cout << "\ntesting range " << someInt.at(8) << "\n";

    try {

    } catch (out_of_range) {
        cerr << "catched an out of range error.....\n";
    }

}
