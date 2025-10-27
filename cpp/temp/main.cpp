#include <iostream>
using namespace std;

// solve quadratic equation --- use quadratic formula to find x, and then plug that into the equation to verify

int main() {
    double a = {};
    double b = {};
    double c = {};

    cout << "solve for the quadratic equation, provide a b and c (double values): ";
    cin >> a >> b >> c;
    cout << "\n";

    // so we use here the quadratic formula to find x first (two solutions for x1 and x2)
    double x1 = (-(b) + (sqrt((pow(b, 2)) - ((4*a)*c)))) / (2*a);
    double x2 = (-(b) - (sqrt((pow(b, 2)) - ((4*a)*c)))) / (2*a);
    cout << "x1 is " << x1 << "\n";
    cout << "x2 is " << x2 << "\n";

    // this is the quadratic equation
    //ax2 + bx + c
    x1 = (a*(pow(x1, 2))) + (b*x1) + c;
    x2 = (a*(pow(x2, 2))) + (b*x2) + c;

    if (x1 == 0 && x2 == 0) {
        cout << "valid inputs\n";
    } else {
        cout << "------------ >> invalid inputs aka no real roots in math\n";
    }
}