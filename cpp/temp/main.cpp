#include <iostream>
using namespace std;

// implement full try catch with user-defined expect design pattern
// this time using the template plus lambda
// i dont fully understand template and lamdas .. just testing if i can do this

void error(string e);
int area(int length, int width);
template<typename Whatever>
void expect(Whatever preconditionCheck, string someErrorMessgae) {
    if (!preconditionCheck()) error(someErrorMessgae);
}



int main() {
    try {
        cout << area(2, 99);
    } catch (runtime_error& e) {
        cerr << "ERROR: " << e.what() << "\n";
    }
}

int area(int length, int width) {
    expect([&](){ return length > 0 && width > 0; }, "non-positive length or width...");

    // intentionally added -9999 here to test the postcondition
    expect([length, width](){ return (length * width)-9999 > 0; },"invalid area...");
    return length * width;
}


void error(string e) {
    throw runtime_error {e};
}

