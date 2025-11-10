/*
    This is the first version of the calculator from Chapter 5.
    It is the version referred to as calculator00.cpp in section 5.6.
    It correctly handles precedence but has a bug where it "eats"
    tokens that it doesn't use, leading to strange behavior.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

// Use std:: for all standard library components
using namespace std;

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
  
  Token(char k) :kind{k}, value{0.0}{}
  Token(char k, double v) :kind{k}, value{v}{}
};

// ------------------------------------------------------------------
// get_token() function (deduced from Chapter 5.8.2)
// This is the standalone version *before* Token_stream
// ------------------------------------------------------------------

Token get_token()
{
  char ch;
  cin >> ch; // note that >> skips whitespace

  switch (ch) {
  case '(': case ')': case '+': case '-': case '*': case '/':
    return Token{ch}; // let each character represent itself
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
// Grammar Functions (from Chapter 5.5)
// ------------------------------------------------------------------

double expression(); // Declaration needed for primary() to call expression()

// ------------------------------------------------------------------
// Handle Numbers and Parentheses (from Chapter 5.5.4)
// ------------------------------------------------------------------
double primary()
{
  Token t = get_token();
  switch (t.kind) {
  case '(': // handle '(' expression ')'
  { 
    double d = expression();
    t = get_token();
    if (t.kind != ')')
    error("')' expected");
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
// Handle * and / (from Chapter 5.5.3, with % removed)
// ------------------------------------------------------------------
double term()
{
  double left = primary();
  Token t = get_token(); // get the next token
  while (true) {
  switch (t.kind) {
  case '*':
    left  *= primary();
    t = get_token();
    break;
  case '/':
  { 
    double d = primary();
    if (d == 0)
    error("divide by zero");
    left /= d;
    t = get_token();
    break;
  }
  default:
    // This is the bug! It "eats" the token.
    return left; // finally: no more * or /
  }
  }
}

// ------------------------------------------------------------------
// Handle + and - (from Chapter 5.5.2.3)
// ------------------------------------------------------------------
double expression()
{
  double left = term(); // read and evaluate a Term
  Token t = get_token(); // get the next token
  while (true) {
  switch (t.kind) {
  case '+':
    left += term(); // evaluate Term and add
    t = get_token();
    break;
  case '-':
    left -= term(); // evaluate Term and subtract
    t = get_token();
    break;
  default:
    // This is the bug! It "eats" the token.
    return left; // finally: no more + or -
  }
  }
}

// ------------------------------------------------------------------
// main() function (from Chapter 5.6)
// ------------------------------------------------------------------

int main()
try{
  while (cin) // this will always be good as it entered the loop for the first time!
    cout << expression() << " is the result <<<======\n";
}
catch (exception& e) {
  cerr << e.what() << '\n';
  return 1;
}
catch (...) {
  cerr << "exception \n";
  return 2;
}