#include <iostream>
using namespace std;

int area(int length, int width);

int main() {
    int x = area(2,3);
    cout << x;
}

// if i delete this part (the function definition), it wil give a linker error
int area(int length, int width) {
    return length * width;
}


