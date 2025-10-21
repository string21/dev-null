#include <iostream>
using namespace std;


int main () {

    int i = 0;

    while (i < 26   ) {

        cout << char('a' + i) << "\t" << (int) char('a' + i) << "\n";

        ++i;
    }

    return 0;
}
