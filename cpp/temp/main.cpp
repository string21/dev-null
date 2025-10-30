#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>

using namespace std;

int area(int len, int wid);
bool validInputForAreaCheck(int len, int wid);


void expect(function<bool()> condition, string errMsg) {
    if (!condition)
        throw runtime_error(errMsg);
}

int main() {
    try {
        cout << area(2,2);
    } catch(runtime_error& e) {
        cerr << e.what();
    }
}


int area(int len, int wid) {
    expect([&]{ return len > 0 && wid > 0; }, "non-positive length or width");
    return len * wid;
}

bool validInputForAreaCheck(int len, int wid) {
    if (len > 0 && wid > 0) return true;
    return false;
}

