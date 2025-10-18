#include <iostream>

using namespace  std;

// so when age is set to a string and results to 0 instead of -1 -- this is non-standard but common
// should i switch to linux?

int main () {

    //just another test for cin

    cout << "enter name and age: ";
    string name = "???";
    int age = -1;

    cin >> name >> age;

    //cout << "helloww, " << name << "! (" << age << " years old)\n";

    cout << cin.good();

    if (cin) { // or cin.good()
        cout << "helloww, " << name << "! (" << age << " years old)\n";
    } else {
        cout << "value of name is: " << name << "\n";
        cout << "value of age is: " << age << "\n";
    }

    return 0;

}

/*
 * the "places" in which we store data in memory are called object, a named object is called variable
 * = is called an initializer
 * the reason for the name double is historical, it is short for double-precision floating point
 * >> this is the input operator
 * << this of course is the output operator
 * reading string into a variable using cin is terminated by a whitespace!! (so i tried this i can do either return key or simple space)
 * whitespaces are all ignored by the >> operator in cin
 * i get the >> is sensitive to type but i dont get who << is sensitive to type
 */




