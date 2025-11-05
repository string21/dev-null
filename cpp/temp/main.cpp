#include <iostream>
using namespace std;

void error(string e) {
    throw runtime_error {e};
}

int main()
{
    int lval = 0;
    int rval = 0;

    cout << "Please enter expression (we can handle +, −,  *, and /\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";

    cin>>lval; // read left-most operand
    if (!cin) error("no first operand");

    for (char op; cin>>op;) {

        cout << "operator captured is " << op << "\n";

        if (op=='x') {
            cout << "Result: " << lval << '\n';
            return 0; // they chose x to exit clean per user instructions
        } else  {
            cin >> rval; // read right-hand operand

            if (cin.good()) cout << "cin is good\n";
            if (!cin.good()) cout << "cin is bad\n";

            if (!cin) error("no second operand");
        }

        switch(op){
            case '+':
                lval += rval; // add: lval = lval + rval
                break;
            case '-':
                lval -= rval; // subtract: lval = lval - rval
                break;
            case '*':
                lval  *= rval; // multiply: lval = lval * rval
                break;
            case '/':
                lval /= rval; // divide: lval = lval / rval
                break;
            default:
                error("invalid operator\n");
        }
    }
    error("bad expression");
}