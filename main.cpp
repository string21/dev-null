//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

#include "std_lib_facilities.h"


void what(string what, string value) {
    cout << what << " with value of " << value << "\n";
}

void what(string what, double value) {
    cout << what << " with value of " << value << "\n";
}

void what(string what, int value) {
    cout << what << " with value of " << value << "\n";
}

void what(string what, char value) {
    cout << what << " with value of " << value << "\n";
}

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit" -- now changed to x for "exit" per drill
    case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': // added curly braces here per drill
    case '!':
        // cout << "returning symbol from token get: " << ch << "\n";
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        // cout << "returning float from token get: " << val << "\n";
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
    return 0; // satisfy compiler
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

int get_factorial(int num) {
    int res = 1;
    for (int i=1; i <= num; ++i) {
        res *= i;
    }
    return res;
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
            return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    case 'x':
        error("bye bye..."); // this is temporary... so i can exit this route
        break;
    default:
        error("primary expected");
    }
    return 0; // satisfy compiler
}
//------------------------------------------------------------------------------

// deal with ! (factorial of an "integer")

double factorial() {
    double left = primary(); // getting a double back

    if (left-std::floor(left) > 0) { // floaring point? then we cant feed that into factorial...
        cout << "hey!!! factorial() on " << left << "\n";
        error("factorial error");
    }

    Token t = ts.get();

    while(true) {
        switch(t.kind) {
            case '!':
                // treating psuedo int starts and ends with this function call
                left = (double)get_factorial((int)left); // narrow in widen back to double type
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left; 
        }
    }

    return 0.00; // satisfy compiler
}




//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = factorial();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Enter expressions using floating-point numbers.\n"
    << "'x' to exit and '=' to print ...\n> ";
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'x') {
            cout << "got the x, im quitting here...\n";
            break; // 'q' for quit
        }

        if (t.kind == '=')        // ';' for "print now"
            cout << "=" << val << '\n';
        else {
            ts.putback(t);
        }

        val = expression();
    }
    // keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    // keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    // keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------