#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int area(int len, int wid);
void expect(bool condition, string errMsg);

int main() {
    try {
        cout << area(2,0);
    } catch(runtime_error& e) {
        cerr << e.what();
    }
}

int area(int len, int wid) {
    expect(len > 0 && wid > 0, "non-positive length or width");
    return len * wid;
}

void expect(bool condition, string errMsg) {
    if (!condition)
        throw runtime_error(errMsg);
}