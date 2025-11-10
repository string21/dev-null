/*
    This is the "second version" of the calculator from Chapter 5,
    referred to in the book as calculator01.cpp (section 5.7).

    This version introduces the Token_stream class to solve the
    "token-eating" bug by providing get() and putback().

    It also adds ';' as a "print" command and 'q' as a "quit" command.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

// Using standard library components explicitly
using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::runtime_error;
using std::exception;

// ------------------------------------------------------------------
// Error function (from Chapter 4.6.3)
// ------------------------------------------------------------------
void error(string s)
{
    throw runtime_error(s);
}

// ------------------------------------------------------------------
// Token class (from Chapter 5.3.3)
// ------------------------------------------------------------------
class Token {
public:
    char kind;
    double value;
    
    // Constructor for operators/parentheses
    Token(char k) :kind{k}, value{0.0}{}
    // Constructor for numbers
    Token(char k, double v) :kind{k}, value{v}{}
};

// ------------------------------------------------------------------
// Token_stream class (from Chapter 5.8)
// ------------------------------------------------------------------
class Token_stream {
public:
    Token_stream() :full{false}, buffer{'\0'} { }
    Token get();            // get a Token
    void putback(Token t);  // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

// --- Token_stream member function definitions ---

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;     // copy t to buffer
    full = true;    // buffer is now full
}

Token Token_stream::get()
{
    if (full) {     // do we already have a Token ready?
        full = false; // remove Token from buffer
        return buffer;
    }

    char ch;
    cin >> ch; // note that >> skips whitespace

    switch (ch) {
    // Operators, parentheses, print, and quit:
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ch}; // let each character represent itself
    
    // Numeric literals:
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    { 
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val; // read a floating-point number
        return Token{'8',val}; // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
    return Token{'\0'}; // Unreachable, to satisfy compiler
}

// ------------------------------------------------------------------
// Global Token_stream
// ------------------------------------------------------------------
Token_stream ts;        // provides get() and putback()

// ------------------------------------------------------------------
// Grammar Functions (from Chapter 5.7)
// ------------------------------------------------------------------

double expression(); // Declaration needed for primary() to call expression()

// ------------------------------------------------------------------
// Handle Numbers and Parentheses (Chapter 5.5.4, modified for Token_stream)
// ------------------------------------------------------------------
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(': // handle '(' expression ')'
    { 
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '8': // '8' represents "a number"
        return t.value; // return the number’s value
    default:
        error("primary expected");
    }
    return 0; // Unreachable
}

// ------------------------------------------------------------------
// Handle * and / (Chapter 5.7)
// ------------------------------------------------------------------
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next Token from the Token stream
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        { 
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t); // put t back into the token stream
            return left;
        }
    }
}

// ------------------------------------------------------------------
// Handle + and - (Chapter 5.7)
// ------------------------------------------------------------------
double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get(); // get the next Token from the Token stream
    while (true) {
        switch (t.kind) {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t); // put t back into the token stream
            return left; // finally: no more + or -
        }
    }
}

// ------------------------------------------------------------------
// main() function (from Chapter 5.7, version 3)
// ------------------------------------------------------------------
int main()
try {
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'q') break; // 'q' for "quit"
        if (t.kind == ';')        // ';' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "exception \n";
    return 2;
}