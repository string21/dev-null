#include <iostream>
using namespace std;

void error(string e) {
    throw runtime_error {e};
}

int main()
{
    cout << "Please enter expression (we can handle +, −,  *, and /\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    int lval = 0;
    int rval = 0;
    cin>>lval; // read left-most operand
    if (!cin)
        error("no first operand");

    for (char op; cin>>op;) { // read operator and right-hand op
        cout << "operator captured is " << op << "\n";
        if (op!='x')
            cin>>rval;
        else {
            cout << "we received the x request, show the result...";
        }

        if (cin.good()) cout << "cin is good\n";
        if (!cin.good()) cout << "cin is bad\n";

        if (!cin)
            error("no second operand");

        if (op == 'x') {
            cout << "Result: " << lval << '\n';
            return 0;
        } else {
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
                    error("invalid op\n");

            }
        }
    }
    error("bad expression");
}