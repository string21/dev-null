#include <iostream>
using namespace std;

// this is catching all logic errors by adding tests / conditions to filter inputs and test return values
// so .... we cannot have a negative amount of space or "negative area" that's not logical that our code will accept that
// that should be considered a bug or error in logic...

// this helps reinforce the concepts of testing for errors in the function itself (callee) and thej caller of the function

// key takeaways
// putting some tests in the function itself -- callee handles the tests
// putting the burden to the caller to add some tests to make sure the arguments passed onto the function are valid
// also make sure to handle return values!!

// one more so with error checking in the callee function -- im testing the logical inputs instead of the result of
// the calculation -- in short -- test the inputs!!

// framed area is full width heigh minus the frame or some inner border

int area(int num1, int num2);
int framed_area(int num1, int num2, int frame_number);
void error(string msg);
int someFunc(int x, int y, int z);

int main() {

    someFunc(10, 8, 5);

}

int someFunc(int x, int y, int z) {

    int frame_number = 2;

    // x and y here is given by the drill
    int area1 = area(x,y);
    cout << "area1 is " << area1 << "\n";

    // 1 and z here is given by the drill
    int area2 = framed_area(1,z,frame_number);
    cout << "area2 is " << area2 << "\n";

    // y and z here is given by the drill
    int area3 = framed_area(y,z, frame_number);
    cout << "area3 is " << area3 << "\n";

    if (area1 == -1 || area2 == -1 || area3 == -1 ) {
        error("bad area detected\n");
        cout << "someFunc returned bad\n";
        return -1;
    }
    double ratio = double(area1)/area3;
    cout << "ratio is " << ratio << "\n";
    cout << "someFunc returned good\n";
    return 0;
}
int area(int w, int h) {
    if (w <= 0 || h <= 0) {
        cout << "bad area >> non-positive width or height\n";
        return -1;
    }
    return w * h;
}
int framed_area(int w, int h, int frame_number) {
    if (w-frame_number <= 0 || h-frame_number <= 0) {
        cout << "bad framed_area >> non-positive width or height\n";
        return -1;
    }
    return (w-frame_number) * (h-frame_number);
}
void error(string msg) {
    cerr << msg;
}