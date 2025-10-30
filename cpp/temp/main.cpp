#include <iostream>
using namespace std;

// implement full try catch with user-defined expect design pattern

void error(string e);
int area(int length, int width);
void expect(bool preconditionCheck, string eMsg);

int main() {
    try {
        cout << area(0, 2);
    } catch (runtime_error& e) {
        cerr << "ERROR: " << e.what() << "\n";
    }
}

int area(int length, int width) {
    expect(length > 0 && width > 0, "non-positive length or width...");
    return length * width;
}

void expect(bool preconditionCheck, string eMsg) {
    if (!preconditionCheck) error(eMsg);
}

void error(string e) {
    throw runtime_error {e};
}